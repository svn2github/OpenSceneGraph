
#include "FFmpegDecoder.hpp"

#include <osg/Notify>

#include <cassert>
#include <limits>
#include <stdexcept>
#include <string.h>



namespace osgFFmpeg {



FFmpegDecoder::FFmpegDecoder() :
    m_audio_stream(0),
    m_video_stream(0),
    m_audio_queue(100),
    m_video_queue(100),
    m_audio_decoder(m_audio_queue, m_clocks),
    m_video_decoder(m_video_queue, m_clocks),
    m_state(NORMAL),
    m_loop(false)
{

}



FFmpegDecoder::~FFmpegDecoder()
{
    close(true);
}


bool FFmpegDecoder::open(const std::string & filename)
{
    try
    {
        // Open video file
        AVFormatContext * p_format_context = 0;

        if (filename.compare(0, 5, "/dev/")==0)
        {
            avdevice_register_all();
        
            osg::notify(osg::NOTICE)<<"Attempting to stream "<<filename<<std::endl;

            AVFormatParameters formatParams;
            memset(&formatParams, 0, sizeof(AVFormatParameters));
            AVInputFormat *iformat;

            formatParams.channel = 0;
            formatParams.standard = 0;
            formatParams.width = 640;
            formatParams.height = 480;
            formatParams.time_base.num = 1;
            formatParams.time_base.den = 50;

            iformat = av_find_input_format("video4linux2");
            
            if (iformat)
            {
                osg::notify(osg::NOTICE)<<"Found input format"<<std::endl;
            }
            else
            {
                osg::notify(osg::NOTICE)<<"Failed to find input_format"<<std::endl;
            }

            if (av_open_input_file(&p_format_context, filename.c_str(), iformat, 0, &formatParams) != 0)
                throw std::runtime_error("av_open_input_file() failed");
        }
        else
        {
            if (av_open_input_file(&p_format_context, filename.c_str(), 0, 0, 0) !=0 )
                throw std::runtime_error("av_open_input_file() failed");
        }
        
        m_format_context.reset(p_format_context);

        // Retrieve stream info
        if (av_find_stream_info(p_format_context) < 0)
            throw std::runtime_error("av_find_stream_info() failed");

        m_duration = double(m_format_context->duration) / AV_TIME_BASE;
        m_start = double(m_format_context->start_time) / AV_TIME_BASE;

        // TODO move this elsewhere
        m_clocks.reset(m_start);

        // Dump info to stderr
        dump_format(p_format_context, 0, filename.c_str(), false);

        // Find and open the first video and audio streams (note that audio stream is optional and only opened if possible)

        findVideoStream();
        findAudioStream();

        m_video_decoder.open(m_video_stream);

        try
        {
            m_audio_decoder.open(m_audio_stream);
        }

        catch (const std::runtime_error & error)
        {
            osg::notify(osg::WARN) << "FFmpegImageStream::open audio failed, audio stream will be disabled: " << error.what() << std::endl;
        }
    }

    catch (const std::runtime_error & error)
    {
        osg::notify(osg::WARN) << "FFmpegImageStream::open : " << error.what() << std::endl;
        return false;
    }
    
    return true;
}



void FFmpegDecoder::close(bool waitForThreadToExit)
{
    flushAudioQueue();
    flushVideoQueue();
    
    m_audio_decoder.close(waitForThreadToExit);
    m_video_decoder.close(waitForThreadToExit);
}



bool FFmpegDecoder::readNextPacket()
{
    switch (m_state)
    {
    case NORMAL:
        return readNextPacketNormal();

    case END_OF_STREAM:
        return readNextPacketEndOfStream();

    case REWINDING:
        return readNextPacketRewinding();

    default:
        assert(false);
        return false;
    }
}



void FFmpegDecoder::rewind()
{
    m_pending_packet.clear();

    flushAudioQueue();
    flushVideoQueue();
    rewindButDontFlushQueues();
}




void FFmpegDecoder::findAudioStream()
{
    for (unsigned int i = 0; i < m_format_context->nb_streams; ++i)
    {
        if (m_format_context->streams[i]->codec->codec_type == CODEC_TYPE_AUDIO)
        {
            m_audio_stream = m_format_context->streams[i];
            m_audio_index = i;
            return;
        }
    }

    m_audio_stream = 0;
    m_audio_index = std::numeric_limits<unsigned int>::max();
}



void FFmpegDecoder::findVideoStream()
{
    for (unsigned int i = 0; i < m_format_context->nb_streams; ++i)
    {
        if (m_format_context->streams[i]->codec->codec_type == CODEC_TYPE_VIDEO)
        {
            m_video_stream = m_format_context->streams[i];
            m_video_index = i;
            return;
        }
    }

    throw std::runtime_error("could not find a video stream");
}



inline void FFmpegDecoder::flushAudioQueue()
{
    FFmpegPacketClear pc;
    m_audio_queue.flush(pc);
}



inline void FFmpegDecoder::flushVideoQueue()
{
    FFmpegPacketClear pc;
    m_video_queue.flush(pc);
}



bool FFmpegDecoder::readNextPacketNormal()
{
    AVPacket packet;

    if (! m_pending_packet)
    {
        bool end_of_stream = false;

        // Read the next frame packet
        if (av_read_frame(m_format_context.get(), &packet) < 0)
        {
            if (url_ferror(m_format_context->pb) == 0)
                end_of_stream = true;
            else
                throw std::runtime_error("av_read_frame() failed");
        }

        if (end_of_stream)
        {
            // If we reach the end of the stream, change the decoder state
            if (loop())
                rewindButDontFlushQueues();
            else
                m_state = END_OF_STREAM;

            return false;
        }
        else
        {
            // Make the packet data available beyond av_read_frame() logical scope.
            if (av_dup_packet(&packet) < 0)
                throw std::runtime_error("av_dup_packet() failed");

            m_pending_packet = FFmpegPacket(packet);            
        }
    }

    // Send data packet
    if (m_pending_packet.type == FFmpegPacket::PACKET_DATA)
    {
        if (m_pending_packet.packet.stream_index == m_audio_index)
        {
            if (m_audio_queue.timedPush(m_pending_packet, 10)) {
                m_pending_packet.release();
                return true;
            }
        }
        else if (m_pending_packet.packet.stream_index == m_video_index)
        {
            if (m_video_queue.timedPush(m_pending_packet, 10)) {
                m_pending_packet.release();
                return true;
            }
        }
        else
        {
            m_pending_packet.clear();
            return true;
        }
    }

    return false;
}



bool FFmpegDecoder::readNextPacketEndOfStream()
{
    const FFmpegPacket packet(FFmpegPacket::PACKET_END_OF_STREAM);

    m_audio_queue.timedPush(packet, 10);
    m_video_queue.timedPush(packet, 10);

    return false;
}
    


bool FFmpegDecoder::readNextPacketRewinding()
{
    const FFmpegPacket packet(FFmpegPacket::PACKET_FLUSH);

    if (m_audio_queue.timedPush(packet, 10) && m_video_queue.timedPush(packet, 10))
        m_state = NORMAL;

    return false;
}



void FFmpegDecoder::rewindButDontFlushQueues()
{
    const AVRational AvTimeBaseQ = { 1, AV_TIME_BASE }; // = AV_TIME_BASE_Q

    const int64_t pos = m_clocks.getStartTime() * AV_TIME_BASE;
    const int64_t seek_target = av_rescale_q(pos, AvTimeBaseQ, m_video_stream->time_base);

    if (av_seek_frame(m_format_context.get(), m_video_index, seek_target, 0/*AVSEEK_FLAG_BYTE |*/ /*AVSEEK_FLAG_BACKWARD*/) < 0)
        throw std::runtime_error("av_seek_frame failed()");

    m_state = REWINDING;
}



} // namespace osgFFmpeg

// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/AudioStream>
#include <osg/CopyOp>
#include <osg/Object>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/observer_ptr>
        
BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::AudioSink)
	I_DeclaringFile("osg/AudioStream");
	I_BaseType(osg::Object);
	I_Constructor0(____AudioSink,
	               "",
	               "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method0(void, play,
	          Properties::PURE_VIRTUAL,
	          __void__play,
	          "",
	          "");
	I_Method0(void, pause,
	          Properties::PURE_VIRTUAL,
	          __void__pause,
	          "",
	          "");
	I_Method0(void, stop,
	          Properties::PURE_VIRTUAL,
	          __void__stop,
	          "",
	          "");
	I_Method0(bool, playing,
	          Properties::PURE_VIRTUAL,
	          __bool__playing,
	          "",
	          "");
	I_Method0(double, getDelay,
	          Properties::VIRTUAL,
	          __double__getDelay,
	          "",
	          "");
	I_Method1(void, setDelay, IN, const double, delay,
	          Properties::VIRTUAL,
	          __void__setDelay__C5_double,
	          "",
	          "");
	I_Method1(void, setVolume, IN, float, x,
	          Properties::VIRTUAL,
	          __void__setVolume__float,
	          "",
	          "");
	I_Method0(float, getVolume,
	          Properties::VIRTUAL,
	          __float__getVolume,
	          "",
	          "");
	I_SimpleProperty(double, Delay, 
	                 __double__getDelay, 
	                 0);
	I_SimpleProperty(float, Volume, 
	                 __float__getVolume, 
	                 __void__setVolume__float);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::AudioStream::SampleFormat)
	I_DeclaringFile("osg/AudioStream");
	I_EnumLabel(osg::AudioStream::SAMPLE_FORMAT_U8);
	I_EnumLabel(osg::AudioStream::SAMPLE_FORMAT_S16);
	I_EnumLabel(osg::AudioStream::SAMPLE_FORMAT_S24);
	I_EnumLabel(osg::AudioStream::SAMPLE_FORMAT_S32);
	I_EnumLabel(osg::AudioStream::SAMPLE_FORMAT_F32);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::AudioStream)
	I_DeclaringFile("osg/AudioStream");
	I_BaseType(osg::Object);
	I_Constructor0(____AudioStream,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::AudioStream &, audio, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____AudioStream__C5_AudioStream_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setAudioSink, IN, osg::AudioSink *, audio_sink,
	          Properties::PURE_VIRTUAL,
	          __void__setAudioSink__osg_AudioSink_P1,
	          "",
	          "");
	I_Method2(void, consumeAudioBuffer, IN, void *const, buffer, IN, const size_t, size,
	          Properties::PURE_VIRTUAL,
	          __void__consumeAudioBuffer__void_P1C5__C5_size_t,
	          "",
	          "");
	I_Method0(int, audioFrequency,
	          Properties::PURE_VIRTUAL,
	          __int__audioFrequency,
	          "",
	          "");
	I_Method0(int, audioNbChannels,
	          Properties::PURE_VIRTUAL,
	          __int__audioNbChannels,
	          "",
	          "");
	I_Method0(osg::AudioStream::SampleFormat, audioSampleFormat,
	          Properties::PURE_VIRTUAL,
	          __SampleFormat__audioSampleFormat,
	          "",
	          "");
	I_SimpleProperty(osg::AudioSink *, AudioSink, 
	                 0, 
	                 __void__setAudioSink__osg_AudioSink_P1);
END_REFLECTOR


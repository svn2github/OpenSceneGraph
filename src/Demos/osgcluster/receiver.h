#ifndef __RECEIVER_H
#define __RECEIVER_H


////////////////////////////////////////////////////////////
// Receiver.h
//
// Class definition for the recipient of a broadcasted message
//

#ifndef WIN32
    #include <netinet/in.h>
#endif

class Receiver 
{
    public :

	Receiver();
	~Receiver();

   	// setBuffer defines the buffer into which the broadcasted
	// message will be received.
	void setBuffer( void *buffer, const unsigned int size );

 	// Define what port to listen and bind to
	void setPort( const short port );

	// Sync does a blocking wait to recieve next message
	void sync( void );

    private :
	bool init( void );

    private :
#if defined (WIN32)
        SOCKET _so;
#else
    int _so;
#endif
#if defined (WIN32)
        SOCKADDR_IN saddr;
#else
        struct sockaddr_in saddr;
#endif
    bool _initialized;
    short _port;
    void *_buffer;
    unsigned int _buffer_size;
};
#endif 

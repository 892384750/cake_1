 ///
 /// @file    SocketIO.h
 /// @author  bgx@rong
 /// @date    2018-07-08 00:21:51
 ///
 
#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

#include "Noncopyable.h"

#include <unistd.h>

namespace bgx
{

class SocketIO
	: Noncopyable
{
	public:
		SocketIO(int fd);

		ssize_t readn(char * buff, size_t count);
		ssize_t writen(const char * buff, size_t count);
		ssize_t readline(char * buff, size_t max);

	private:
		ssize_t readPeek(char * buff, size_t count);

	private:
		int _fd;
};	

}// end of namespace bgx.

#endif

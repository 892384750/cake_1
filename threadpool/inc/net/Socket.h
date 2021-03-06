 ///
 /// @file    Socket.h
 /// @author  bgx@rong
 /// @date    2018-07-07 23:18:10
 ///
 
#ifndef __SOCKET_H__
#define	__SOCKET_H__

#include "Noncopyable.h"

namespace bgx
{

class InetAddress;

class Socket
	: Noncopyable
{
	public:
		Socket();
		Socket(int);
		void ready(InetAddress & addr);
		int accept();
		int fd();

		void shutdownWrite();

		static InetAddress getLocalAddr(int fd);
		static InetAddress getPeerAddr(int fd);

	private:
		void setReuseAddr(bool flag);
		void setReusePort(bool flag);
		void bind(InetAddress & addr);
		void listen();

	private:
		int _fd;
};

}

#endif

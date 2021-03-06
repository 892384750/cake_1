 ///
 /// @file    InetAddress.cc
 /// @author  bgx@rong
 /// @date    2018-07-07 23:25:54
 ///
 
#include "InetAddress.h"

#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

namespace bgx
{

	InetAddress::InetAddress(unsigned short port)
	{
		memset(&_addr, 0 , sizeof(struct sockaddr_in));
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = INADDR_ANY;
	}

	InetAddress::InetAddress(const char * ip, unsigned short port)
	{
		memset(&_addr, 0 , sizeof(struct sockaddr_in));
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = inet_addr(ip);
	}

	InetAddress::InetAddress(const struct sockaddr_in & addr)
	: _addr(addr)
	{	}

	struct sockaddr_in * InetAddress::getInetAddressPtr()
	{	return &_addr;	}

	std::string InetAddress::ip() const
	{	return std::string(inet_ntoa(_addr.sin_addr));	}

	unsigned short InetAddress::port() const
	{	return ntohs(_addr.sin_port);	}

}

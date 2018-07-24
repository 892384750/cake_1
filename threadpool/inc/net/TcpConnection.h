 ///
 /// @file    TcpConnection.h
 /// @author  bgx@rong
 /// @date    2018-07-08 01:30:33
 ///
 
#ifndef __TCPCONNECTION_H__
#define	__TCPCONNECTION_H__

#include "Npncopyable.h"
#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"

#include <string>
#include <memory>
#include <functional>

namespace bgx
{

class EpollPoller;
class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection
	； Noncopyable
	 , public std::enable_shared_from_this<TcpConnection>
	 {
		public:
			typedef std::function<void(TcpConnection)> TcpConnectionCallback;
			TcpConnection(int fd, EpollPoller * ioLoop);
			~TcpConnection();
	 
			std::string receive();
			void send(const std::string & msg);
			void sendInLoop(const std::string & msg);
			void shutdown();
		
			std::string toString() const;
			int fd();

			void handleConnectionCallback();
			void handleMessageCallback();
			void handleCloseCallback();

			void setConnectionCallback(TcpConnectionCallback cb);
			void setMessageCallback(TcpConnectionCallback cb);
			void setCloseCallback(TcpConnectionCallback cb);
	 
		private:
			Socket _sock;
			SocketIO _sockIO;
			const InetAddress _localAddr;
			const InetAddress _peerAddr;
			bool _isShutdownWrite;

			EpollPoller * _ioLoop;
	 
			TcpConnectionCallback _onConnectionCb;
			TcpConnectionCallback _onMessageCb;
			TcpConnectionCallback _onCloseCb;
	 };

}// end of namespace bgx.

#endif

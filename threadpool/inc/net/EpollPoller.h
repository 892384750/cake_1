 ///
 /// @file    EpollPoller.h
 /// @author  bgx@rong
 /// @date    2018-07-08 02:43:57
 ///
 
#ifndef __EPOLLPOLLER_H__
#define	__EPOLLPOLLER_H__

#include "Noncopyable.h"
#include "TcpConnection.h"
#include "MutexLock.h"

#include <sys/epoll.h>
#include <vector>
#include <map>
#include <functional>

using std::vector;
using std::map;

namespace bgx
{

class EpollPoller
	: Noncopyable
{
	public:
		typedef std::function<void(TcpConnectionPtr)> EpollPollerCallback;
		typedef std::function<void()> Functor;
		EpollPoller(int listenfd);
		~EpollPoller();
	
		void loop();
		void unloop();
		void runInLoop(const Functor & cb);

		void wakeup();
		void handleRead();
		void doPendingFunctors();

		void setConnectionCallback(EpollPollerCallback cb);
		void setMessageCallback(EpollPollerCallback cb);
		void setCloseCallback(EpollPollerCallback cb);

	private:
		int _epollfd;
		int _eventfd;
		int _listenfd;
		bool _isLooping;

		MutexLock _mutex;
		vector<Functor> _pendingFunctors;

		vector<struct epoll_event> _eventList;
		map<int,TcpConnectionPtr> _connMap;

		EpollPollerCallback _onConnection;
		EpollPollerCallback _onMessage;
		EpollPollerCallback _onClose;
};

}// end of namespace bgx.

#endif

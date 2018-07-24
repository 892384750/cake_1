 ///
 /// @file    Thread.h
 /// @author  bgx@rong
 /// @date    2018-07-06 06:10:52
 ///
 
#ifndef __THREAD_H__
#define __THREAD_H__

#include "Noncopyable.h"

#include <pthread.h>
#include <string>
#include <functional>
#include <sstream>

using std::string;

namespace bgx
{

inline string int2str(int number)
{
	std::ostringstream oss;
	oss << number;
	return oss.str();
}

inline unsigned short srt2unshort(const string & str)
{
	unsigned short port;
	std::istringstream iss(str);
	iss >> port;
	return port;
}

inline int str2int(const string & str)
{
	int number;
	std::istringstream iss(str);
	iss >> number;
	return number;
}

namespace current_thread
{
	extern __thread const char * threadName;// __thread为线程全局变量的声明，每个线程中都有它的一个实例，可以说每个线程的__thread都是独立的。
}//end of namespaec current_thread.

class Thread
: Noncopyable
{
	public:
		typedef std::function<void()> ThreadCallback;
		Thread(ThreadCallback cb,const string & name = string ());
		~Thread();

		void start();
		void join();
		pthread_t getThreadId() const
		{	return _pthId;	}

		static void * threadFunc(void * arg);

	private:
		pthread_t _pthId;
		bool _isRunning;
		ThreadCallback _cb;
		string _name;
};

}//end of namespace bgx

#endif

 ///
 /// @file    TimerThread.h
 /// @author  bgx@rong
 /// @date    2018-07-08 06:48:52
 ///
 
#ifndef __TIMERTHREAD_H__
#define __TIMERTHREAD_H__

#include "Timer.h"
#include "Thread.h"

#include <functional>

namespace bgx
{

class TimerThread
{

	public:
		typedef std::function<void()> TimerThreadCallback;

		TimerThread(TimerThreadCallback cb,int init_sec,int interval_sec);

		void start();
		void stop();

	private:
		Timer _timer;
		Thread _thread;
};

}// end of namespace bgx.

#endif

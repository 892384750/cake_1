 ///
 /// @file    Timer.h
 /// @author  bgx@rong
 /// @date    2018-07-08 06:24:23
 

#ifndef __TIMER_H__
#define __TIMER_H__

#include "Noncopyable.h"

#include <iostream>
#include <functional>

class Timer
: bgx::Noncopyable
{
	public:
		typedef std::function<void()> TimerCallback;
		Timer(TimerCallback cb, int init_sec,int interval_sec);
		~Timer();

		void start();
		void stop();

	private:
		int _fd;
		TimerCallback _cb;
		bool _isStarted;
};

#endif

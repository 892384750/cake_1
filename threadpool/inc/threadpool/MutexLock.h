 ///
 /// @file    MutexLock.h
 /// @author  bgx@rong
 /// @date    2018-07-06 23:33:23
 ///
 
#ifndef __MUTEXLOCK_H__
#define	__MUTEXLOCK_H__

#include "Noncopyable.h"

#include <pthread.h>

namespace bgx
{

class MutexLock
	: Noncopyable
{
	public:
		MutexLock();
		~MutexLock();

	void lock();
	void unlock();
	pthread_mutex_t * getMutexLockPtr();

	private:
		pthread_mutex_t _mutex;
		bool _isLocking;
};

class MutexLockGuard
{
	public:
		MutexLockGuard(MutexLock & mutex)
			: _mutex(mutex)
			{	_mutex.lock();	}

		~MutexLockGuard()
		{	_mutex.unlock();	}

	private:
		MutexLock & _mutex;
};

}// end of namespace bgx.

#endif

 ///
 /// @file    MutexLock.cc
 /// @author  bgx@rong
 /// @date    2018-07-07 00:35:14
 ///
 
#include "MutexLock.h"

#include <iostream>

namespace bgx
{

	MutexLock::MutexLock()
		: _isLocking(false)
		{	pthread_mutex_init(&_mutex,NULL);	}

	MutexLock::~MutexLock()
	{	pthread_mutex_destroy(&_mutex);	}

	void MutexLock::lock()
	{
		pthread_mutex_lock(&_mutex);
		_isLocking = true;
	}

	void MutexLock::unlock()
	{
		pthread_mutex_unlock(&_mutex);
		_isLocking = false;
	}

	pthread_mutex_t * MutexLock::getMutexLockPtr()
	{	return &_mutex;	}

} // end of namespace bgx.

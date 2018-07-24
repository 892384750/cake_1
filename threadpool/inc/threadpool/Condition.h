 ///
 /// @file    Condition.h
 /// @author  bgx@rong
 /// @date    2018-07-07 00:10:11
 ///
 
#ifndef __CONDITION_H__
#define	__CONDITION_H__

#include "Noncopyable.h"

#include <pthread.h>

namespace bgx
{

class MutexLock;

class Condition
	: Noncopyable
{
	public:
		Condition(MutexLock & mutex);
		~Condition();

		void wait();
		void notify();
		void notiftAll();

	private:
		pthread_cond_t _cond;
		MutexLock & _mutex;
};

}// end of namespace bgx.

#endif

 ///
 /// @file    Buffer.h
 /// @author  bgx@rong
 /// @date    2018-07-07 00:58:58
 ///
 
#ifndef __BUFFER_H__
#define	__BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"

#include <queue>
#include <functional>

class Cache;

namespace bgx
{

class Buffer
{
	public:
		typedef std::function<void ()> Task;
		Buffer(int size);
		~Buffer();

		void push(Task ptask);
		Task pop();

		bool full();
		bool empty();

	private:
		int _size;
		std::queue<Task> _que;
		MutexLock _mutex;
		Condition _notFull;
		Condition _notEmpty;
};

}// end of namespace bgx.


#endif

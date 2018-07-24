 ///
 /// @file    Buffer.cc
 /// @author  bgx@rong
 /// @date    2018-07-07 01:18:33
 ///
 
#include "Buffer.h"

namespace bgx
{

	Buffer::Buffer(int size)
		: _size(_size)
		  , _mutex()
		   , _notFull(_mutex)
			, _notEmpty(_mutex)
			{	}

	Buffer::~Buffer()
	{	}

	bool Buffer::full()
	{	return _size == _que.size();	}

	bool Buffer::empty()
	{	return 0 == _que.size();	}

	void Buffer::push(Task ptask)
	{
		MutexLockGuard mlg(_mutex);
		// _mutex.lock();
		while(full())
			_notFull.wait();
		_que.push(ptask);

		// _mutex.unlock();
		_notEmpty.notify();
	}

	Buffer::Task Buffer::pop()
	{
		MutexLockGuard mlg(_mutex);
		// _mutex.lock()
		while(empty())
			_notEmpty.wait();

		Task ptask = _que.front();
		_que.pop();

		// _mutex.unlock();
		_notFull.notify();
		return ptask;
	}

}// end of  namespace bgx.

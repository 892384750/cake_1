 ///
 /// @file    Threadpool.h
 /// @author  bgx@rong
 /// @date    2018-07-07 03:12:54
 ///
 
#ifndef __THREADPOOL_H__
#define	__THREADPOOL_H__

#include "Buffer.h"
#include "MyConf.h"

#include <vector>
#include <functional>

using std::vector;

namespace bgx
{
 
class Thread;

class Threadpool
{
	public:
		typedef std::function<void ()> Task;
		Threadpool(int threadNum, int bufSize);
		~Threadpool();

		void start();
		void stop();

		void addTask(Task task);

		void threadFunc();

	private:
		Task getTask();

	private:
		int _threadNum;
		vector<Thread *> _vecThreads;
		int _bufSize;
		Buffer _buf;
		bool _isExit;
};

}// end of namespace bgx.

#endif

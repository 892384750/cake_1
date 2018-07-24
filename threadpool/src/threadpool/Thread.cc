 ///
 /// @file    Thread.cc
 /// @author  bgx@rong
 /// @date    2018-07-07 00:44:01
 ///
 
#include "Thread.h"

#include <iostream>

namespace bgx
{

namespace current_thread
{	__thread const char * threadName = "bgx";	}

struct ThreadData
{
	typedef Thread::ThreadCallback ThreadCallback;
	ThreadCallback _cb; // 线程的执行函数。
	string _name; // 线程名字。
	
	ThreadData(const ThreadCallback & cb , const string & name )
	: _cb(cb)
	  , _name(name)
		{	}

	void runInThread()
	{
		current_thread::threadName = _name.empty() ? "bgx" : _name.c_str();
	// 给线程命名，若空，则赋默认值 "bgx", 否则用传入参数个线程命名。
		if(_cb)
			_cb(); // 若处理函数不为空，则准备进行处理函数的运行。
	}

};

Thread::Thread(ThreadCallback cb , const string & name)
	: _pthId(0)
	  , _isRunning(false)
	   , _cb(cb)
		, _name(name)
		{	}

Thread::~Thread()
{
	if(_isRunning)
		pthread_detach(_pthId); // 线程运行完之后，会自动释放资源。
}

void Thread::start()
{
	ThreadData * pdata = new ThreadData(_cb,_name);
	pthread_create(&_pthId,NULL,&Thread::threadFunc,pdata);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning)
		pthread_join(_pthId , NULL);
}

void * Thread::threadFunc(void * arg)
{
	ThreadData * pdata = static_cast<ThreadData *> (arg);
	if(pdata)
		pdata->runInThread(); //进行处理函数的运行。

	delete pdata;
}// 线程函数

}// end of namespace bgx.

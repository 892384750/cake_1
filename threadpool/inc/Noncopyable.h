 ///
 /// @file    Noncopyable.h
 /// @author  bgx@rong
 /// @date    2018-07-06 01:41:09
 ///
 
#ifndef __NONCOPYABLE_H__ 
#define	__NONCOPYABLE_H__

namespace bgx
{

class Noncopyable
{
	protected:
		Noncopyable(){}
		~Noncopyable(){}

	private:
		Noncopyable(const Noncopyable &);
		Noncopyable & operator= (const Noncopyable &);
};

}

#endif

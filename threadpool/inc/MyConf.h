 ///
 /// @file    MyConf.h
 /// @author  bgx@rong
 /// @date    2018-07-07 06:52:17
 ///
 
#ifndef __MYCONF_H__
#define	__MYCONF_H__

#include <string>
#include <map>

using std::map;
using std::string;

class MyConf
{
	public:
		static MyConf * getInstance();

		map<string,string> & getMap()	{	return _map;	}
		
		bool init(const string & filename);

		void show();

	private:
		MyConf(){}
	
		~MyConf(){}

	private:
		map<string,string> _map;

		static MyConf * _pInstance;
};

#endif

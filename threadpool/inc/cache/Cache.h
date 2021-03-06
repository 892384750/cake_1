 ///
 /// @file    Cache.h
 /// @author  bgx@rong
 /// @date    2018-07-07 05:03:33
 ///
 
#ifndef __CACHE_H__
#define __CACHE_H__

#include <iostream>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;

class Cache
{
	public:
		void readFromFile(const string & filename);

		void writeToFile(const string & filename);
	
		void update(const Cache & rhs);

		void addElement(const string & key , const string & value);

		void debug();

		string query(const string & word);

	private:
		unordered_map<string,string> _hashMap;
};

#endif

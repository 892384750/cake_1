 ///
 /// @file    Cache.cc
 /// @author  bgx@rong
 /// @date    2018-07-07 05:09:02
 ///
 
#include "Cache.h"

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

void Cache::addElement(const string & key , const string & value)
{	_hashMap[key] = value;	}

string Cache::query(const string & word)
{
	auto iter = _hashMap.find(word);
	if(iter != _hashMap.end())
	{	
		return iert->second;		
	}else
	{
		return string();
	}
}// 在cache中查询，找到则返回内容，否则返回空。

void Cache::readFromFile(const string & filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout << "open cache file error!" << endl;
		return ;
	}

	string key,value;
	while(ifs >> key >> value)
	{	_hashMap.insert(std::make_pair(key,value));	}
}

void Cache::writeToFile(const string & filename)
{
	ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		cout << "ofstream:write cache file error!" << endl;
		return ;
	}

	auto iter = _hashMap.begin();
	for(; iter != _hashMap.end(); ++iter)
	{
		ofs << iter->first << "\t" << iter->second << endl;
	}
	ofs.close();
}

void Cache::update(const Cache & rhs)
{
	auto iter = rhs._hashMap.begin();
	for(; iter != rhs._hashMap.end(); ++iter)
	{
		_hashMap.insert(*iter);
	}
}

void Cache::debug()
{
	cout << "Cache begin:" << endl;
	for(auto & elem : _hashMap)
	{
		cout << elem.first << "-->" << elem.second << endl;
	}
	cout << "Cache end: " << endl;
}

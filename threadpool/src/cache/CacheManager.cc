 ///
 /// @file    CacheManager.cc
 /// @author  bgx@rong
 /// @date    2018-07-07 06:04:28
 ///
 
#include "CacheManager.h"
#include "MyConf.h"

#include <iostream>

using std::cout;
using std::endl;

vector<Cache> CacheManeger::_cacheList;

void CacheManeger::initCache(size_t sz, const string & filename)
{
	Cache cache;
	cache.readFromFile(filename);

	for(size_t idx = 0; idx != sz; ++idx)
		_cacheList.push_back(cache);
}

Cache & CacheManeger::getCache(size_t idx)
{	return _cacheList[idx];	}

void CacheManeger::periodicUpdateCaches()
{
	cout << "> Staring update Caches!" << endl;
	auto it1 = _cacheList.begin();
	auto it2 = ++it1;
	for(; it2 != _cacheList.end(); ++it2)
	{
		it1->update(*it2);
	}
	
	it1 = _cacheList.begin();
	it2 = ++it1;
	for(; it2 != _cacheList.end(); ++it2)
	{
		it2->update(*it1);
	}
	//	存储到本地。
	it1 -> writeToFile(MyConf::getInstance()->getMap()["my_cache"]);
}

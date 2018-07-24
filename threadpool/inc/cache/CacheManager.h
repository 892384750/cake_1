 ///
 /// @file    CacheManager.h
 /// @author  bgx@rong
 /// @date    2018-07-07 05:52:06
 ///
 
#ifndef __CACHEMANAGER_H__
#define	__CACHEMANAGER_H__

#include "Cache.h"

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class CacheManager
{
	public:
		static void initCache(size_t sz, const string & filename);
		static Cache & getCache(size_t idx);
		static void periodicUpdateCaches();
	
	private:
		static vector<Cache> _cacheList;
};

#endif

#ifndef LRUCACHE_H
#define LRUCACHE_H
#include "Cache.h"
#include <unordered_map>
#include<list>

using namespace std;


class LRUCache : public Cache{
    private:
    int capacity;
    //doubly linkedlist to store key value pair
    list<pair<int, int>> dll;

     // hashedmap : key -> iterator to dll node
    unordered_map<int, list<pair<int,int>>::iterator>cacheMap;

    public:
     LRUCache(int cap);
     int get(int key)override;
     void put (int key , int value)override;

};

#endif
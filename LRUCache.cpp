#include "LRUCache.h"
#include <iostream>

LRUCache ::LRUCache(int cap){
    capacity= cap;
}
//get operation

int LRUCache :: get(int key){
    //if key not found
    if(cacheMap.find(key)== cacheMap.end()){
        return -1;
    }
   // move accessed node to front
    auto node = cacheMap[key];
    int value = node->second;

    dll.erase(node);
    dll.push_front({key,value});
    cacheMap[key] = dll.begin();

    return value;
}
//put operation
void LRUCache :: put(int key, int value){
    // if key already exist
    if(cacheMap.find(key)!= cacheMap.end()){
        dll.erase(cacheMap[key]);
    }
    //if cache is full
    else if(dll.size()== capacity){
        auto last = dll.back();
        cacheMap.erase(last.first);
        dll.pop_back();
    }

    //insert new node at front
    dll.push_front({key, value});
    cacheMap[key] = dll.begin();
}

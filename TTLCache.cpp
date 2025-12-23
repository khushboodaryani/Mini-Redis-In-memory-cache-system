#include<iostream>
#include "TTLCache.h"

TTLCache :: TTLCache(int ttl){
    ttlSeconds = ttl;
}

int TTLCache :: get(int key){
  
    auto it = cache.find(key);
  if(it == cache.end()){
    return -1;
  }

  auto now = chrono::steady_clock::now();
  // current time > expire time
  // second --> {value, expire_time}
  //second.second = expire_time
  if(now > it->second.second){
    cache.erase(it); // lazy deletion , delete only when access
    return -1;
  }
  return it->second.first ; // return value
}
void TTLCache :: put(int key , int value){
    // current time + ttl eg: 12:00:00 + 5 sec , expiry = 12:00::05
   auto expiryTime = chrono::steady_clock::now() + chrono::seconds(ttlSeconds);
   cache[key]= {value , expiryTime}; // insert new key if not present , update value + expiry if already present
}
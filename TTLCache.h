#ifndef TTLCACHE_H
#define TTLCACHE_H
#include <unordered_map>
#include "Cache.h"
#include <chrono>
#include <list>

using namespace std;

class TTLCache : public Cache
{
private:
    int ttlSeconds;

    // list<pair<int, chrono::steady_clock>>dll;

    // key -> {value, expiry_time}
    // expire logic-- if ( current_time > expiry_time)--> delete
    unordered_map<int, pair<int, chrono::steady_clock::time_point>>
        cache; // safe clock (never goes backward)
    // time_point -> exact momemnt
    // lazy expire
    // if key exist check its current time vs exoire time and delete it else return value
public:
    TTLCache(int ttl);
    int get(int key) override;
    void put(int key, int value) override;
};

#endif
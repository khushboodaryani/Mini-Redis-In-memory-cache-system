#include <iostream>
#include "LRUCache.h"
#include "TTLCache.h"
#include <thread>
using namespace std;

int main(){

    // LRUCache cache(2);
 
    // cache.put(1,10);
    // cache.put(2,10);

    // cout<< cache.get(1)<<endl;
    // cache.put(3,30);

    // cout<< cache.get(2)<<endl;
    // cout<< cache.get(3)<<endl;

    TTLCache cache (5);
    cache.put(1,100);
    cout<<"Value: "<< cache.get(1)<<endl;
    
    // trigger TTL
    this_thread::sleep_for(chrono::seconds(4));
    
    cout <<" after expiry: "<< cache.get(1)<<endl;

    return 0;
}
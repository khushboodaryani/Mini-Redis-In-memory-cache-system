#ifndef CACHE_H
#define CACHE_H //header guards 
// if cache_h not define
// define it

class Cache {
    public:
    virtual int get(int key) = 0; // pure virtual class
    virtual void put(int key , int val)=0; 
    virtual ~Cache(){} // virtual destructor of the base class Cache this is important it
    // without virtual destructor derived cleaned up skipped follow proper cleanup and prevent memory leak
    // it first run derived class destructor then base class destrctor  prevent memory leak 
};

// else ignore it
#endif

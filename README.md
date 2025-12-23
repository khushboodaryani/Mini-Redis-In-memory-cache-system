Mini Redis-Like In-Memory Cache (C++)
Overview
This project is a mini Redis-style in-memory cache system built in C++ to understand cache eviction strategies, data structures, and low-level system design.
It is designed to be extensible, allowing multiple cache strategies through a common interface.
Implemented Strategies
LRU (Least Recently Used) – Evicts the least recently accessed item when capacity is full.
TTL (Time To Live) – Expires cache entries automatically after a fixed time duration.
Design
Uses Strategy Pattern via a common Cache interface
Focus on O(1) operations using unordered_map and linked lists
Clean separation of interface and implementations

Folder Structure
Cache.h
LRUCache.h / LRUCache.cpp
TTLCache.h / TTLCache.cpp
main.cpp

How to Run
g++ main.cpp LRUCache.cpp TTLCache.cpp -o cache
./cache

Purpose
Built as a learning-focused system project to apply DSA + OOP concepts and understand how Redis-like caches work internally.
More eviction strategies will be added in future.

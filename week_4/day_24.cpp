/**

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

**/


class LRUCache {
public:
    int cap, cur;
    unordered_map<int,list<pair<int,int>>::iterator >exists;
    list<pair<int,int> >cache;
    
    LRUCache(int capacity) {
        cap = capacity;
        exists.clear();
        cur = 0;
    }
    
    int get(int key) {
        auto fnd = exists.find(key);
        if(fnd == exists.end()) return -1;
        cache.splice(cache.begin(),cache,fnd->second);
        return fnd->second->second;
    }
    
    void put(int key, int value) {
        auto fnd = exists.find(key);
        if(fnd != exists.end()) // key exists
        {
            cache.splice(cache.begin(),cache,fnd->second);
            fnd->second->second = value;
            return;
        }
        if(cur == cap) // reached capacity
        {
            int key_to_del = cache.back().first;
            cache.pop_back();
            exists.erase(key_to_del);
            cur--;
        }
        cur++;
        cache.push_front({key,value});
        exists[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
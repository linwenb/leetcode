/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache{
public:
    LRUCache(int capacity):maxCapa(capacity) {}
    
    int get(int key) {
        unordered_map<int, list<int>::iterator>::iterator p = pos.find(key);
        if (p == pos.end())   return -1;    //  not found

        lru.erase(p->second);
        lru.push_front(key);
        pos[key] = lru.begin();
        
        return mp[key];
    }   //  O(1) time, O(1) space
    
    void set(int key, int value) {
        unordered_map<int, list<int>::iterator>::iterator p = pos.find(key);
        
        if (p != pos.end()) {
            lru.erase(p->second);
        }   //  found
        else if (lru.size() == maxCapa) {
            int temp = lru.back();  // key of least recently used item
            pos.erase(temp);
            mp.erase(temp);
            lru.pop_back();
        }   //  not found, and full
        
        //  its pos in lru is begin()
        lru.push_front(key);
        pos[key] = lru.begin();
        mp[key] = value;
    }   //  O(1) time, O(1) space

private:
    list<int> lru;
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> pos;
    int maxCapa;
};
/*
[LeetCode] 146. LRU Cache
https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
public:
    int size;
    list<int> LRUList;
    unordered_map<int, int> cache_map;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cache_map.find(key) == cache_map.end())
            return -1;
        else {
            LRUList.remove(key);
            LRUList.push_back(key);
            return cache_map[key];
        }
    }
    
    void put(int key, int value) {
        if(cache_map.find(key) != cache_map.end()) {
            LRUList.remove(key);
            LRUList.push_back(key);
            cache_map[key] = value;
        }
        else if(LRUList.size() == size && size == cache_map.size()) {
            cache_map.erase(LRUList.front());
            LRUList.pop_front();
            LRUList.push_back(key);
            cache_map[key] = value;
        }else{
            LRUList.push_back(key);
            cache_map[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
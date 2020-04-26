class LRUCache {
public:
    int size;
    list<int> lru;
    unordered_map<int, list<int>::iterator> it;
    unordered_map<int, int> mp;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.count(key) == 0) {
            return -1;
        }
        update(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.size() == size && mp.count(key) == 0) {
            evict(key);
        }
        update(key);
        mp[key] = value;
    }
    
    void update(int key) {
        if(mp.count(key)) {
            lru.erase(it[key]);
        }
        lru.push_front(key);
        it[key] = lru.begin();
    }
    
    void evict(int key) {
        mp.erase(lru.back());
        it.erase(lru.back());
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

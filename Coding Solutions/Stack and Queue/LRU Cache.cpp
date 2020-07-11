class LRUCache {
    int limit;
    list<int> used;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator it)
    {
        used.erase(it->second.second);
        used.push_front(it->first);
        it->second.second = used.begin();
    }
public:
    LRUCache(int capacity) {
        limit = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            return -1;
        }
        touch(it);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            touch(it);
        }
        else
        {
            if (used.size() == limit)
            {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
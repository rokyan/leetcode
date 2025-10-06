class LRUCache
{
public:
    LRUCache(int capacity)
        : capacity{capacity}
    {
    }
    
    int get(int key)
    {
        if (auto it = keyToIter.find(key); it != std::end(keyToIter))
        {
            ordered.splice(std::begin(ordered), ordered, it->second);
            it->second = std::begin(ordered);
            return it->second->second;
        }

        return -1;
    }
    
    void put(int key, int value)
    {
        if (auto it = keyToIter.find(key); it != std::end(keyToIter))
        {
            it->second->second = value;
            ordered.splice(std::begin(ordered), ordered, it->second);   
            it->second = std::begin(ordered);
        }
        else
        {
            ordered.emplace_front(key, value);
            keyToIter.emplace(key, std::begin(ordered));

            if (std::size(keyToIter) > capacity)
            {
                const int keyToRemove = std::rbegin(ordered)->first;
                ordered.pop_back();
                keyToIter.erase(keyToRemove);
            }
        }  
    }

private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> keyToIter;
    std::list<std::pair<int, int>> ordered;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache
{
private:
    using list_of_pairs = std::list<std::pair<int, int>>;

public:
    LRUCache(int capacity)
        : capacity{capacity}
    {}
    
    int get(int key)
    {
        if (const auto it = key_to_pos.find(key); it != std::end(key_to_pos))
        {
            const auto value = it->second->second;
            values.erase(it->second);
            values.emplace_front(key, value);
            it->second = std::begin(values);
            return value;
        }

        return -1;
    }
    
    void put(int key, int value)
    {
        if (const auto it = key_to_pos.find(key); it != std::end(key_to_pos))
        {
            values.erase(it->second);
            values.emplace_front(key, value);
            it->second = std::begin(values);
        }
        else
        {
            if (std::size(values) == capacity)
            {
                key_to_pos.erase(values.back().first);
                values.pop_back();
            }
            values.emplace_front(key, value);
            key_to_pos[key] = std::begin(values);
        }
    }

private:
    int capacity;
    std::unordered_map<int, list_of_pairs::iterator> key_to_pos;
    list_of_pairs values;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
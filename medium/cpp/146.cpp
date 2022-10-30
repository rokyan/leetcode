// https://leetcode.com/problems/lru-cache/

class LRUCache
{
public:
    LRUCache(int capacity)
        : capacity(capacity)
    {   
    }
    
    int get(int key)
    {
        auto it = keys_to_values.find(key);
        
        if (it == std::end(keys_to_values))
        {
            return -1;
        }
        
        auto value = it->second->second;
        
        values.erase(it->second);
        values.push_back({ key, value });
        it->second = --std::end(values);
        
        return value;
    }
    
    void put(int key, int value)
    {
        auto it = keys_to_values.find(key);
        
        if (it != std::end(keys_to_values))
        {
            values.erase(it->second);
            values.push_back({ key, value });
            it->second = --std::end(values);
        }
        else
        {
            if (std::size(keys_to_values) == capacity)
            {
                auto old_key = std::begin(values)->first;
                values.erase(std::begin(values));
                keys_to_values.erase(old_key);
            }
            
            values.push_back({ key, value });
            keys_to_values.insert({ key, --std::end(values) });
        }
    }
    
private:
    int capacity;
    std::list<std::pair<int, int>> values;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> keys_to_values;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
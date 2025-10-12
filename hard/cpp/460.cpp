// https://leetcode.com/problems/lfu-cache/description/

class LFUCache
{
private:
    struct Entry
    {
        int freq;
        int timestamp;
        int value;
        std::set<std::tuple<int, int, int>>::iterator orderPointer;
    };

public:
    LFUCache(int capacity)
        : capacity{capacity}
        , timestamp{0}
    {        
    }
    
    int get(int key)
    {
        if (capacity == 0)
        {
            return -1;
        }

        if (const auto it = data.find(key); it != std::end(data))
        {
            auto& [freq, modifiedTimestamp, lastValue, orderPointer] = it->second;
        
            order.erase(orderPointer);
            freq++;
            modifiedTimestamp = timestamp++;
            orderPointer = order.insert({freq, modifiedTimestamp, key}).first;

            return lastValue;
        }

        return -1;
    }
    
    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }

        if (const auto it = data.find(key); it != std::end(data))
        {
            auto& [freq, modifiedTimestamp, lastValue, orderPointer] = it->second;
        
            order.erase(orderPointer);
            freq++;
            modifiedTimestamp = timestamp;
            lastValue = value;
            orderPointer = order.insert({freq, modifiedTimestamp, key}).first;
        }
        else
        {
            if (std::size(data) == capacity)
            {
                const auto [freq, modifiedTimestamp, key] = *std::cbegin(order);
                data.erase(key);
                order.erase(std::cbegin(order));
            }

            data[key] = {1, timestamp, value,  order.insert({1, timestamp, key}).first};
        }

        timestamp++;
    }

private:
    int capacity;
    int timestamp;
    std::unordered_map<int, Entry> data;
    std::set<std::tuple<int, int, int>> order;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
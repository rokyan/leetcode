// https://leetcode.com/problems/stock-price-fluctuation/

class StockPrice
{
public:
    StockPrice()
        : curr_val(0)
        , last_timestamp(0)
    {
        
    }
    
    void update(int timestamp, int price)
    {
        if (timestamp >= last_timestamp)
        {
            last_timestamp = timestamp;
            curr_val = price;
        }
        
        const auto it = timestamp_to_it.find(timestamp);
        
        if (it == std::end(timestamp_to_it))
        {
            const auto ins_it = values.insert(price);
            timestamp_to_it.emplace(timestamp, ins_it);
        }
        else
        {
            values.erase(it->second);
            it->second = values.insert(price);
        }
    }
    
    int current()
    {
        return curr_val;
    }
    
    int maximum()
    {
        return *std::rbegin(values);
    }
    
    int minimum()
    {
        return *std::begin(values);
    }
    
private:
    std::unordered_map<int, std::multiset<int>::iterator> timestamp_to_it;
    std::multiset<int> values;
    int curr_val;
    int last_timestamp;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
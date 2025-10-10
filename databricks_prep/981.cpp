class TimeMap
{
public:
    TimeMap() = default;
    
    void set(const std::string& key, const std::string& value, int timestamp)
    {
        data[key][timestamp] = value;
    }
    
    std::string get(const std::string& key, int timestamp)
    {
        const auto key_it = data.find(key);

        if (key_it == std::end(data))
        {
            return "";
        }

        const auto& values = key_it->second;

        auto value_it = values.upper_bound(timestamp);

        if (value_it == std::begin(values))
        {
            return "";
        }

        return std::prev(value_it)->second;
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
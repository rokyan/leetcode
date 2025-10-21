// https://leetcode.com/problems/all-oone-data-structure/description/

class AllOne
{
public:
    AllOne() = default;
    
    void inc(const std::string& key)
    {
        const int newFreq = ++freq[key];

        if (newFreq > 1)
        {
            remove(key, newFreq - 1);
        }

        keysWithFreq[newFreq].insert(key);
    }
    
    void dec(const std::string& key)
    {
        const int newFreq = --freq[key];

        remove(key, newFreq + 1);

        if (newFreq > 0)
        {
            keysWithFreq[newFreq].insert(key);
        }
    }
    
    std::string getMaxKey()
    {
        if (keysWithFreq.empty())
        {
            return "";
        }

        return *std::cbegin(std::rbegin(keysWithFreq)->second);
    }
    
    std::string getMinKey()
    {
        if (keysWithFreq.empty())
        {
            return "";
        }

        return *std::cbegin(std::begin(keysWithFreq)->second);
    }

private:
    void remove(const std::string& key, int count)
    {
        if (const auto it = keysWithFreq.find(count); it != std::cend(keysWithFreq))
        {
            it->second.erase(key);

            if (std::size(it->second) == 0)
            {
                keysWithFreq.erase(it);
            }
        }
    }

private:
    std::unordered_map<std::string, int> freq;
    std::map<int, std::unordered_set<std::string>> keysWithFreq;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// https://leetcode.com/problems/first-unique-number/description/

class FirstUnique
{
public:
    FirstUnique(const std::vector<int>& nums)
    {
        for (auto num : nums)
        {
            add(num);
        }
    }
    
    int showFirstUnique()
    {
        return n.empty() ? -1 : *std::cbegin(n);
    }
    
    void add(int value)
    {
        if (auto it = m.find(value); it != std::end(m))
        {
            if (it->second.first)
            {
                n.erase(it->second.second);
                it->second.first = false;
            }
        }
        else
        {
            n.push_back(value);
            m.emplace(value, std::make_pair(true, std::prev(std::end(n))) );
        }
    }

private:
    std::unordered_map<int, std::pair<bool, std::list<int>::iterator>> m;
    std::list<int> n;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
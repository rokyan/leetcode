// https://leetcode.com/problems/random-pick-index/

class Solution
{
public:
    Solution(std::vector<int>& nums)
        : gen(rd())
        , distr(0.0, 1.0)
    {
        for (std::size_t pos = 0; pos < std::size(nums); pos++)
        {
            auto it = val_to_indexes.find(nums[pos]);
            
            if (it == std::end(val_to_indexes))
            {
                std::vector<std::size_t> poss { pos };
                val_to_indexes.insert(std::make_pair(nums[pos], poss));
            }
            else
            {
                it->second.push_back(pos);
            }
        }
    }
    
    int pick(int target)
    {
        auto it = val_to_indexes.find(target);
        auto pos = static_cast<std::size_t>(std::size(it->second) * distr(gen));
        return it->second[pos];
    }
    
private:
    std::unordered_map<int, std::vector<std::size_t>> val_to_indexes;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> distr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
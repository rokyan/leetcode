// https://leetcode.com/problems/non-decreasing-subsequences/description/

namespace std
{
    template<>
    struct hash<std::vector<int>>
    {
        // https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector        
        size_t operator()(const std::vector<int>& v) const
        {
            std::size_t hash = std::size(v);

            for(auto&& e : v)
            {
                hash ^= e + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }

            return hash;
        }
    };
}

class Solution
{
public:    
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) 
    {
        const auto n = std::size(nums);
        
        std::unordered_set<std::vector<int>> res;
        std::vector<int> cur;
        
        for (auto mask = 1; mask < (1 << n); mask++)
        {
            auto increasing = true;
            cur.clear();
            
            for (auto bit = 0; bit < n; ++bit)
            {
                if (mask & (1 << bit))
                {
                    if (cur.empty() || cur.back() <= nums[bit])
                    {
                        cur.push_back(nums[bit]);
                    }
                    else
                    {
                        increasing = false;
                        break;
                    }
                }
            }
            
            if (increasing && std::size(cur) > 1)
            {
                res.insert(cur);
            }
        }
        
        return std::vector<std::vector<int>>(std::begin(res), std::end(res));
    }
}; 
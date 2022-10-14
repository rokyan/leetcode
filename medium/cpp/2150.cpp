// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/

class Solution
{
public:
    std::vector<int> findLonely(std::vector<int>& nums)
    {
        std::unordered_map<int, int> counts;
        
        for (auto num : nums) counts[num]++;
        
        std::vector<int> res;
        
        for (const auto& entry : counts)
        {
            if (entry.second == 1 &&
                counts.count(entry.first - 1) == 0 &&
                counts.count(entry.first + 1) == 0)
            {
                res.push_back(entry.first);
            }
        }
        
        return res;
    }
};
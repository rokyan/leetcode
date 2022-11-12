// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution
{
public:
    int countMaxOrSubsets(std::vector<int>& nums)
    {
        const auto max_or = std::accumulate(std::begin(nums), std::end(nums), 0, [](auto acc, auto e) {
            return acc | e;
        });
        
        auto count = 0;
        
        for (int mask = 0; mask < (1 << std::size(nums)); mask++)
        {
            int cur_or = 0;
            
            for (int bit = 0; bit < std::size(nums); bit++)
            {
                if (mask & (1 << bit))
                {
                    cur_or |= nums[bit];
                }
            }
            
            if (cur_or == max_or)
            {
                count++;
            }
        }
        
        return count;
    }
};
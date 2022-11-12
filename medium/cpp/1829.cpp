// https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution
{
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit)
    {
        auto acc = std::accumulate(std::begin(nums), std::end(nums), 0, [](auto acc, auto num) { return acc ^ num; });
        
        std::vector<int> solution;
        solution.reserve((std::size(nums)));
        
        const auto s = (1 << maximumBit) - 1;    
        
        for (int pos = std::size(nums) - 1; pos >= 0; pos--)
        {          
            solution.push_back(acc ^ s);   
            acc ^= nums[pos];
        }
        
        return solution;
    }
};
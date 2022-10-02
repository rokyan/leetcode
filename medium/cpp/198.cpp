// https://leetcode.com/problems/house-robber/

class Solution
{
public:
    int rob(std::vector<int>& nums)
    {
        auto taken = nums.front();
        auto skipped = 0;
        
        for (std::size_t pos = 1; pos < std::size(nums); pos++)
        {
            const auto last_taken = taken;
            
            taken = std::max(taken, skipped + nums[pos]);
            skipped = last_taken;
        }
        
        return std::max(taken, skipped);
    }
};
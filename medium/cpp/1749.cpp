// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution
{
public:
    int maxAbsoluteSum(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
               
        int dp_min = nums[0];
        int dp_max = nums[0];
        
        int ans = std::abs(nums[0]);
        
        for (std::size_t i = 1; i < n; i++)
        {
            dp_max = std::max(nums[i], dp_max + nums[i]);
            dp_min = std::min(nums[i], dp_min + nums[i]);
            
            ans = std::max({ ans, std::abs(dp_max), std::abs(dp_min) });
        }
        
        return ans;
    }
};
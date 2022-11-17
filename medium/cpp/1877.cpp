// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution
{
public:
    int minPairSum(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        int result = -1;
        
        for (std::size_t pos = 0; pos < std::size(nums) / 2; pos++)
        {
            result = std::max(result, nums[pos] + nums[std::size(nums) - pos - 1]);
        }
        
        return result;
    }
};
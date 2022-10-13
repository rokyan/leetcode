// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

class Solution
{
public:
    std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums)
    {
        auto right_sum = std::accumulate(std::begin(nums), std::end(nums), 0);
        auto left_sum = 0;
        
        const auto n = std::size(nums);
        
        std::vector<int> res(n);
        
        for (std::size_t i = 0; i < n; i++)
        {
            res[i] = right_sum - (n - i) * nums[i];
            
            if (i > 0)
            {
                res[i] += i * nums[i] - left_sum;
            }
            
            left_sum += nums[i];
            right_sum -= nums[i];
        }
        
        return res;
    }
};
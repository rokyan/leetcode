// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

class Solution
{
public:
    int maxSumTwoNoOverlap(std::vector<int>& nums, int firstLen, int secondLen)
    {
        return std::max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
    
private:
    int solve(const std::vector<int>& nums, int first_len, int second_len)
    {
        auto first_sum = 0;
        
        for (std::size_t i = 0; i < first_len; i++)
        {
            first_sum += nums[i];
        }
        
        auto second_sum = 0;
        
        for (std::size_t i = first_len; i < first_len + second_len; i++)
        {
            second_sum += nums[i];
        }
        
        auto max_first_sum = first_sum;        
        auto res = max_first_sum + second_sum;
        
        for (std::size_t i = first_len + 1; i + second_len <= std::size(nums); i++)
        {
            first_sum += nums[i - 1];
            first_sum -= nums[i - 1 - first_len];
            
            max_first_sum = std::max(max_first_sum, first_sum);
            
            second_sum += nums[i + second_len - 1];
            second_sum -= nums[i - 1];
            
            res = std::max(res, max_first_sum + second_sum);
        }
        
        return res;
    }
};
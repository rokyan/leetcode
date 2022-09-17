// https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution
{
public:
    int waysToMakeFair(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        auto suff_even = 0;
        auto suff_odd = 0;
        
        for (auto i = 0; i < n; i++)
        {           
            if (i % 2 == 0)
            {
                suff_even += nums[i];
            }
            else
            {
                suff_odd += nums[i];
            }
        }
         
        auto ways = 0;
        
        auto pref_even = 0;
        auto pref_odd = 0;
        
        for (auto i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                suff_even -= nums[i];
            }
            else
            {
                suff_odd -= nums[i];
            }
            
            const auto even_sum = pref_even + suff_odd;
            const auto odd_sum = pref_odd + suff_even;
            
            ways += even_sum == odd_sum;
            
            if (i % 2 == 0)
            {
                pref_even += nums[i];
            }
            else
            {
                pref_odd += nums[i];
            }
        }
        
        return ways;
    }
};

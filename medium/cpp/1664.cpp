// https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution
{
public:
    int waysToMakeFair(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        std::vector<int> suff_even(n);
        std::vector<int> suff_odd(n);
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + 1 < n)
            {
                suff_even[i] = suff_even[i + 1];
                suff_odd[i] = suff_odd[i + 1];
            }
            
            if (i % 2 == 0)
            {
                suff_even[i] += nums[i];
            }
            else
            {
                suff_odd[i] += nums[i];
            }
        }
         
        auto ways = 0;
        
        auto pref_even = 0;
        auto pref_odd = 0;
        
        for (auto i = 0; i < n; i++)
        {
            const auto even_sum = pref_even + (i + 1 < n ? suff_odd[i + 1] : 0);
            const auto odd_sum = pref_odd + (i + 1 < n ? suff_even[i + 1] : 0);
            
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
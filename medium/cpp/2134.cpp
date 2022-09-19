// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution
{
public:
    int minSwaps(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        const int ones = std::count_if(std::begin(nums), std::end(nums), [](auto num) { return num == 1; });
        
        if (ones <= 1 || ones == n)
        {
            return 0;
        }
        
        std::vector<int> pref_sum(n);
        std::partial_sum(std::begin(nums), std::end(nums), std::begin(pref_sum));
        
        int ans = n + 1;
        
        for (std::size_t i = 0; i < n; i++)
        {
            const auto end = std::min(n - 1, i + ones - 1);
            
            auto cnt = pref_sum[end];
            
            if (i > 0)
            {
                cnt -= pref_sum[i - 1];
            }
            
            if (end - i + 1 < ones)
            {
                const auto rem = ones - end + i - 1;
                
                cnt += pref_sum[rem - 1];
            }
            
            ans = std::min(ans, ones - cnt);
        }
        
        return ans;
    }
};
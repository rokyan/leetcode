class Solution
{
public:
    int maxResult(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);
        
        std::multiset<int, std::greater<int>> last_k;
        
        std::vector<int> dp(n);
        dp[0] = nums[0];
        
        for (std::size_t i = 0; i < n; i++)
        {
            dp[i] = *std::begin(last_k) + nums[i];
            
            if (i >= k)
            {
                last_k.erase(last_k.find(dp[i - k]));                
            }

            last_k.insert(dp[i]);
        }
        
        return dp[n - 1];
    }
};
class Solution
{
private:
    static constexpr auto MAX_V = 1000;

public: 
    int findTargetSumWays(std::vector<int>& nums, int target)
    {        
        const auto n = std::size(nums);
        
        std::vector<std::vector<int>> dp(2, std::vector<int>(2 * MAX_V + 1));

        dp[0][MAX_V] = 1;

        for (auto i = 0; i < n; ++i)
        {
            std::fill(std::begin(dp[1]), std::end(dp[1]), 0);
            
            for (auto j = 0; j < 2 * MAX_V + 1; ++j)
            {
                if (dp[0][j] > 0) {
                    dp[1][j + nums[i]] += dp[0][j];
                    dp[1][j - nums[i]] += dp[0][j];
                }
            }
            
            std::swap(dp[0], dp[1]);
        }
        
        return dp[0][target + MAX_V];
    }
};
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution
{
public:
    int findNumberOfLIS(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(2));
        
        dp[0][0] = 1;
        dp[0][1] = 1;
        
        auto max_len = 1;
        auto count = 1;
        
        for (std::size_t i = 1; i < n; i++)
        {
            dp[i][0] = dp[i][1] = 1;
            
            for (std::size_t j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[i][0] < dp[j][0] + 1)
                    {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];                    
                    }
                    else if (dp[i][0] == dp[j][0] + 1)
                    {
                        dp[i][1] += dp[j][1];
                    }
                }
            }
            
            if (dp[i][0] > max_len)
            {
                max_len = dp[i][0];
                count = dp[i][1];
            }
            else if (dp[i][0] == max_len)
            {
                count += dp[i][1];
            }
        }
        
        return count;
    }
};
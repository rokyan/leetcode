// https://leetcode.com/problems/partition-equal-subset-sum/submissions/

class Solution
{
public:
    bool canPartition(std::vector<int>& nums)
    {
        const auto sum = std::accumulate(std::begin(nums), std::end(nums), 0);
        
        if (sum & 1)
        {
            return false;
        }
        
        const auto n = std::size(nums);
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum / 2 + 1));        
                
        for (std::size_t i = 1; i <= n; i++)
        {            
            for (int j = 1; j <= sum / 2; j++)
            {               
                dp[i][j] = dp[i - 1][j];
                
                if (nums[i - 1] == j || nums[i - 1] < j && dp[i - 1][j - nums[i - 1]])
                {
                    dp[i][j] = 1;
                }
            }
        }
               
        return dp[n][sum / 2];
    }
};
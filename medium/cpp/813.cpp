// https://leetcode.com/problems/largest-sum-of-averages/

class Solution
{
public:
    double largestSumOfAverages(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);
        
        std::vector<std::vector<double>> dp(n + 1, std::vector<double>(k + 1));
        
        for (std::size_t i = 1; i <= n; i++)
        {           
            double sum = 0;
            
            for (std::size_t j = i; j >= 1; j--)
            {
                sum += nums[j - 1];
                
                for (int kk = 2; kk <= k; kk++)
                {
                    if (kk > i)
                    {
                        continue;
                    }
                    
                    dp[i][kk] = std::max(dp[i][kk], dp[j - 1][kk - 1] + sum / (i - j + 1));
                }
                
                dp[i][1] = sum / i;
            }
        }
        
        auto ans = 0.0;
        
        for (int kk = 1; kk <= k; kk++)
        {
            ans = std::max(ans, dp[n][kk]);
        }
        
        return ans;
    }
};
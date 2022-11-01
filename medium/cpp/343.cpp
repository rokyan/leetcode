// https://leetcode.com/problems/integer-break/

class Solution
{
public:
    int integerBreak(int n)
    {
        std::vector<int> dp(n + 1);
        
        dp[2] = 1;
        
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = std::max(dp[i], j * (i - j));
            }
            
            for (int j = 1; i - j >= 2; j++)
            {
                dp[i] = std::max(dp[i], dp[i - j] * j);
            }
        }
        
        return dp[n];
    }
};
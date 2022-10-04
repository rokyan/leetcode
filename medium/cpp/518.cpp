// https://leetcode.com/problems/coin-change-ii/

class Solution
{
public:
    int change(int amount, std::vector<int>& coins)
    {
        if (amount == 0)
        {
            return 1;
        }
        
        const int n = std::size(coins);
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1));
        
        dp[0][0] = 1;
                
        for (int i = 1; i <= n; i++)
        {          
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] += dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);   
            }
        }
        
        return dp[n][amount];
    }
};
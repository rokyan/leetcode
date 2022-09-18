// https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution
{
public:
    int numTilings(int n)
    {
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(3));
        
        dp[0][0] = 1;
        dp[1][0] = 1;
        
        const int mod = 1000 * 1000 * 1000 + 7;
        
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % mod;
        }
        
        return dp.back()[0];
    }
};
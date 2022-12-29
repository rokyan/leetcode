// https://leetcode.com/problems/unique-paths/description/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
// https://leetcode.com/problems/maximum-path-score-in-a-grid/description/

class Solution
{
public:
    int maxPathScore(const std::vector<std::vector<int>>& grid, int maxCost)
    {
        const int n = grid.size();
        const int m = grid.front().size();

        std::vector<std::vector<std::vector<int>>> dp(n,
            std::vector<std::vector<int>>(m, std::vector<int>(maxCost + 1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k <= maxCost; k++)
                {
                    int cost = grid[i][j] != 0;

                    if (k >= cost)
                    {
                        if (i > 0 && dp[i - 1][j][k - cost] != -1)
                        {
                            dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k - cost] + grid[i][j]); 
                        }

                        if (j > 0 && dp[i][j - 1][k - cost] != -1)
                        {
                            dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k - cost] + grid[i][j]);
                        }
                    }
                }
            }
        }

        int res = -1;

        for (int k = 0; k <= maxCost; k++)
        {
            if (dp[n - 1][m - 1][k] != -1)
            {
                res = std::max(res, dp[n - 1][m - 1][k]);
            }
        }

        return res;
    }
};
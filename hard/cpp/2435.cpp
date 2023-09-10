// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

class Solution
{
public:
    int numberOfPaths(std::vector<std::vector<int>>& grid, int k)
    {
        const auto mod = 1000 * 1000 * 1000 + 7;

        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(k)));

        dp[0][0][grid[0][0] % k] = 1;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    for (auto r = 0; r < k; r++)
                    {
                        dp[i][j][(grid[i][j] + r) % k] += dp[i - 1][j][r];
                        dp[i][j][(grid[i][j] + r) % k]  %= mod;
                    }
                }

                if (j > 0)
                {
                    for (auto r = 0; r < k; r++)
                    {
                        dp[i][j][(grid[i][j] + r) % k] += dp[i][j - 1][r];
                        dp[i][j][(grid[i][j] + r) % k]  %= mod;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};
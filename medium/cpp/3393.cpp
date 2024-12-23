// https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countPathsWithXorValue(const std::vector<std::vector<int>>& grid, int k)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<std::vector<int>>> dp(n,
            std::vector<std::vector<int>>(m, std::vector<int>(16)));

        dp[0][0][grid[0][0]] = 1;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                for (auto t = 0; t < 16; t++)
                {
                    if (i > 0)
                    {
                        dp[i][j][t] += dp[i - 1][j][t ^ grid[i][j]];
                        dp[i][j][t] %= mod;
                    }

                    if (j > 0)
                    {
                        dp[i][j][t] += dp[i][j - 1][t ^ grid[i][j]];
                        dp[i][j][t] %= mod;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][k];
    }
};
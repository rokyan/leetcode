// https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/description/

class Solution
{
public:
    bool isThereAPath(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        if ((n + m - 1) % 2 == 1)
        {
            return false;
        }

        const auto ones = (n + m - 1) / 2;

        std::vector<std::vector<std::vector<char>>>
            dp(n, std::vector<std::vector<char>>(m, std::vector<char>(ones + 1)));

        std::array<int, 2> di{ 0, -1 };
        std::array<int, 2> dj{ -1, 0 };

        dp[0][0][grid[0][0] == 1] = true;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                for (auto d = 0; d < 2; d++)
                {
                    const auto ni = i + di[d];
                    const auto nj = j + dj[d];

                    if (ni >= 0 && nj >= 0)
                    {
                        for (auto k = 0; k <= ones; k++)
                        {
                            const auto p = k - (grid[i][j] == 1);

                            if (p >= 0)
                            {
                                dp[i][j][k] |= dp[ni][nj][p];
                            }
                        }
                    }
                }
            }
        }

        return dp[n - 1][m - 1][ones];
    }
};
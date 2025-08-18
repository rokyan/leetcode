// https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/description/

class Solution
{
public:
    int minimumOperations(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> dp(m, std::vector<int>(10));

        for (auto d = 0; d <= 9; d++)
        {
            for (auto r = 0; r < n; r++)
            {
                if (grid[r][0] != d)
                {
                    dp[0][d]++;
                }
            }
        }

        for (auto c = 1; c < m; c++)
        {
            for (auto d = 0; d <= 9; d++)
            {
                for (auto r = 0; r < n; r++)
                {
                    if (grid[r][c] != d)
                    {
                        dp[c][d]++;
                    }
                }

                auto prev = d == 0 ? dp[c - 1][1] : dp[c - 1][0];

                for (auto pd = 0; pd <= 9; pd++)
                {
                    if (pd != d)
                    {
                        prev = std::min(prev, dp[c - 1][pd]);
                    }
                }

                dp[c][d] += prev;
            }
        }

        return *std::min_element(std::cbegin(dp[m - 1]), std::cend(dp[m - 1]));
    }
};
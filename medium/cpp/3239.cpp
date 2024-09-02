// https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/

class Solution
{
public:
    int minFlips(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        auto ra = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m / 2; j++)
            {
                ra += grid[i][j] != grid[i][m - j - 1];
            }
        }

        auto ca = 0;

        for (auto j = 0; j < m; j++)
        {
            for (auto i = 0; i < n / 2; i++)
            {
                ca += grid[i][j] != grid[n - i - 1][j];
            }
        }

        return std::min(ra, ca);
    }
};
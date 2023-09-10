// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/

class Solution
{
public:
    std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid)
    {
        const auto n = static_cast<int>(std::size(grid));
        const auto m = static_cast<int>(std::size(grid.front()));

        auto fcc = 0;

        for (auto i = 0; i < n; i++)
        {
            fcc += grid[i][0];
        }

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 1; j < m; j++)
            {
                grid[i][0] += grid[i][j];
            }
        }

        for (auto j = 1; j < m; j++)
        {
            for (auto i = 1; i < n; i++)
            {
                grid[0][j] += grid[i][j];
            }
        }

        for (auto i = n - 1; i >= 0; i--)
        {
            for (auto j = m - 1; j >= 0; j--)
            {
                if (j == 0)
                {
                    grid[i][j] = 2 * (grid[i][0] + fcc) - n - m;
                }
                else
                {
                    grid[i][j] = 2 * (grid[i][0] + grid[0][j]) - n - m;
                }
            }
        }

        return grid;
    }
};
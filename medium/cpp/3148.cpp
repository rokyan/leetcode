// https://leetcode.com/problems/maximum-difference-score-in-a-grid/description/

class Solution
{
public:
    int maxScore(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> min_val(grid);

        auto res = grid[1][1] - grid[0][0];

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    min_val[i][j] = std::min(min_val[i][j], min_val[i - 1][j]);
                    res = std::max(res, grid[i][j] - min_val[i - 1][j]);
                }

                if (j > 0)
                {
                    min_val[i][j] = std::min(min_val[i][j], min_val[i][j - 1]);
                    res = std::max(res, grid[i][j] - min_val[i][j - 1]);
                }
            }
        }

        return res;
    }
};
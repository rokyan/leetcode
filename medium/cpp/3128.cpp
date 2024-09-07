// https://leetcode.com/problems/right-triangles/description/

class Solution
{
public:
    long long numberOfRightTriangles(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> up(n, std::vector<int>(m));
        std::vector<std::vector<int>> down(n, std::vector<int>(m));

        for (auto j = 0; j < m; j++)
        {
            for (auto i = 0, s = 0; i < n; i++)
            {
                up[i][j] = s;
                s += grid[i][j] == 1;
            }

            for (auto i = static_cast<int>(n) - 1, s = 0; i >= 0; i--)
            {
                down[i][j] = s;
                s += grid[i][j] == 1;
            }
        }

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0, s = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    res += 1LL * (up[i][j] + down[i][j]) * s;
                    s++;
                }
            }

            for (auto j = static_cast<int>(m) - 1, s = 0; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    res += 1LL * (up[i][j] + down[i][j]) * s;
                    s++;
                }
            }
        }

        return res;
    }
};
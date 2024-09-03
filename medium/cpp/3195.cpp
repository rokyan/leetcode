// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/

class Solution
{
public:
    int minimumArea(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        auto rs = -1;
        auto re = -1;
        auto cs = static_cast<int>(m);
        auto ce = -1;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    if (rs == -1)
                    {
                        rs = i;
                    }

                    re = i;

                    cs = std::min(cs, j);
                    ce = std::max(ce, j);
                }
            }
        }

        return (re - rs + 1) * (ce - cs + 1);
    }
};
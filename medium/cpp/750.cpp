// https://leetcode.com/problems/number-of-corner-rectangles/description/

class Solution
{
public:
    int countCornerRectangles(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);

        if (n == 0)
        {
            return 0;
        }

        const auto m = std::size(grid.front());

        if (m == 0)
        {
            return 0;
        }

        auto res = 0;

        for (auto rs = 0; rs + 1 < n; rs++)
        {
            for (auto re = rs + 1; re < n; re++)
            {
                auto cnt = 0;

                for (auto c = 0; c < m; c++)
                {
                    if (grid[rs][c] == 1 && grid[re][c] == 1)
                    {
                        cnt++;
                    }
                }

                res += cnt * (cnt - 1) / 2;
            }
        }

        return res;
    }
};
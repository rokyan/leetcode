// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/

class Solution
{
public:
    int numberOfSubmatrices(const std::vector<std::vector<char>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> xcnt(n, std::vector<int>(m));
        std::vector<std::vector<int>> ycnt(n, std::vector<int>(m));

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                xcnt[i][j] += grid[i][j] == 'X';
                ycnt[i][j] += grid[i][j] == 'Y';

                if (i > 0)
                {
                    xcnt[i][j] += xcnt[i - 1][j];
                    ycnt[i][j] += ycnt[i - 1][j];
                }

                if (j > 0)
                {
                    xcnt[i][j] += xcnt[i][j - 1];
                    ycnt[i][j] += ycnt[i][j - 1];
                }

                if (i > 0 && j > 0)
                {
                    xcnt[i][j] -= xcnt[i - 1][j - 1];
                    ycnt[i][j] -= ycnt[i - 1][j - 1];
                }

                if (xcnt[i][j] > 0 && xcnt[i][j] == ycnt[i][j])
                {
                    res++;
                }
            }
        }

        return res;
    }
};
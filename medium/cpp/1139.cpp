// https://leetcode.com/problems/largest-1-bordered-square/description/

class Solution
{
public:
    int largest1BorderedSquare(const std::vector<std::vector<int>>& grid)
    {
        const int n = std::size(grid);
        const int m = std::size(grid.front());

        std::vector<std::vector<int>> maxLeft(n, std::vector<int>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                maxLeft[i][j] = grid[i][j] == 1;

                if (maxLeft[i][j] && j > 0)
                {
                    maxLeft[i][j] += maxLeft[i][j - 1];
                }
            }
        }

        std::vector<std::vector<int>> maxDown(n, std::vector<int>(m));

        for (auto j = 0; j < m; j++)
        {
            for (auto i = n - 1; i >= 0; i--)
            {
                maxDown[i][j] = grid[i][j] == 1;

                if (maxDown[i][j] && i + 1 < n)
                {
                    maxDown[i][j] += maxDown[i + 1][j];
                }
            }
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    auto len = std::max(1, res);

                    while (true)
                    {
                        if (i + len - 1 >= n || j + len - 1 >= m)
                        {
                            break;
                        }

                        auto upd = len;
                        upd = std::min(upd, maxLeft[i][j + len - 1]);
                        upd = std::min(upd, maxLeft[i + len - 1][j + len - 1]);
                        upd = std::min(upd, maxDown[i][j]);
                        upd = std::min(upd, maxDown[i][j + len - 1]);
                        
                        if (upd == len)
                        {
                            res = std::max(res, len);
                        }

                        len++;
                    }
                }
            }
        }

        return res * res;
    }
};
// https://leetcode.com/problems/best-meeting-point/description/

class Solution
{
public:
    int minTotalDistance(std::vector<std::vector<int>>& grid)
    {
        const int n = std::size(grid);
        const int m = std::size(grid.front());

        std::vector<std::vector<int>> d(n, std::vector<int>(m));

        for (auto i = 0, s = 0, tot = 0; i < n; i++)
        {
            s += tot;

            for (auto j = 0; j < m; j++)
            {
                d[i][j] += s;
            }

            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    tot++;
                }
            }
        }

        for (auto i = n - 1, s = 0, tot = 0; i >= 0; i--)
        {
            s += tot;

            for (auto j = 0; j < m; j++)
            {
                d[i][j] += s;
            }

            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    tot++;
                }
            }
        }

        for (auto j = 0, s = 0, tot = 0; j < m; j++)
        {
            s += tot;

            for (auto i = 0; i < n; i++)
            {
                d[i][j] += s;
            }

            for (auto i = 0; i < n; i++)
            {
                if (grid[i][j])
                {
                    tot++;
                }
            }
        }

        for (auto j = m - 1, s = 0, tot = 0; j >= 0; j--)
        {
            s += tot;

            for (auto i = 0; i < n; i++)
            {
                d[i][j] += s;
            }

            for (auto i = 0; i < n; i++)
            {
                if (grid[i][j])
                {
                    tot++;
                }
            }
        }

        auto res = d[0][0];

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                // std::cout << d[i][j] << " ";
                res = std::min(res, d[i][j]);
            }

            // std::cout << std::endl;
        }

        return res;
    }
};
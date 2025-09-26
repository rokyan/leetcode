// https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/

class Solution
{
public:
    std::vector<std::vector<int>> minAbsDiff(const std::vector<std::vector<int>>& grid, int k)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> res(n - k + 1, std::vector<int>(m - k + 1));

        if (k == 1)
        {
            return res;
        }

        for (auto i = 0; i < n - k + 1; i++)
        {
            for (auto j = 0; j < m - k + 1; j++)
            {
                std::set<int> v;

                for (auto ii = i; ii < i + k; ii++)
                {
                    for (auto jj = j; jj < j + k; jj++)
                    {
                        v.insert(grid[ii][jj]);
                    }
                }

                if (std::size(v) == 1)
                {
                    continue;
                }

                auto it = std::cbegin(v);
                auto last = *it++;

                res[i][j] = std::abs(*it - last);

                while (it != std::cend(v))
                {
                    res[i][j] = std::min(res[i][j], std::abs(*it - last));
                    last = *it++;
                }
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/

class Solution
{
public:
    int countSubmatrices(std::vector<std::vector<int>>& grid, int k)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<int> sum(m);

        auto res = 0;

        for (auto i = 0; i < n && sum[0] <= k; i++)
        {
            std::vector<int> cur(m);

            for (auto j = 0; j < m; j++)
            {
                cur[j] = grid[i][j];

                if (i > 0) cur[j] += sum[j];
                if (j > 0) cur[j] += cur[j - 1];
                if (i > 0 && j > 0) cur[j] -= sum[j - 1];

                res += cur[j] <= k;

                if (cur[j] > k)
                {
                    break;
                }
            }

            sum = std::move(cur);
        }

        return res;
    }
};
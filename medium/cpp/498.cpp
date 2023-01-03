// https://leetcode.com/problems/diagonal-traverse/description/

class Solution
{
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat)
    {
        const auto n = static_cast<int>(std::size(mat));
        const auto m = static_cast<int>(std::size(mat.front()));

        std::vector<int> res(n * m);
        auto last = 0;

        for (auto d = 0; d <= n + m - 2; d++)
        {
            if (d % 2 == 0)
            {
                for (auto i = std::min(d, n - 1), j = d - i; i >= 0 && j < m; i--, j++)
                {
                    res[last++] = mat[i][j];
                }
            }
            else
            {
                for (auto j = std::min(d, m - 1), i = d - j; i < n && j >= 0; i++, j--)
                {
                    res[last++] = mat[i][j];
                }
            }
        }

        return res;
    }
};
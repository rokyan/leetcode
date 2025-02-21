class Solution
{
public:
    std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>>& mat)
    {
        const int n = std::size(mat);
        const int m = std::size(mat.front());

        std::vector<int> res;
        res.reserve(n * m);

        for (auto d = 0; d <= n + m - 2; d++)
        {
            if (d % 2 == 0)
            {
                for (auto i = std::min(d, n - 1), j = d - i; i >= 0 && j < m; i--, j++)
                {
                    res.push_back(mat[i][j]);
                }
            }
            else
            {
                for (auto j = std::min(d, m - 1), i = d - j; i < n && j >= 0; i++, j--)
                {
                    res.push_back(mat[i][j]);
                }
            }
        }

        return res;
    }
};
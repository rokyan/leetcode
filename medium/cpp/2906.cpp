// https://leetcode.com/problems/construct-product-matrix/

class Solution
{
private:
    static constexpr auto mod = 12345;

public:
    std::vector<std::vector<int>> constructProductMatrix(std::vector<std::vector<int>>& grid)
    {
        const auto n = static_cast<int>(std::size(grid));
        const auto m = static_cast<int>(std::size(grid.front()));

        std::vector<int> suff(n);

        for (auto i = n - 1; i >= 0; i--)
        {
            suff[i] = 1;

            for (auto j = 0; j < m; j++)
            {
                suff[i] = 1LL * suff[i] * grid[i][j] % mod;
            }

            if (i + 1 < n)
            {
                suff[i] = 1LL * suff[i] * suff[i + 1] % mod;
            }
        }

        auto pref = 1;

        std::vector<std::vector<int>> res(n, std::vector<int>(m));

        for (auto i = 0; i < n; i++)
        {
            auto cur = pref;

            if (i + 1 < n)
            {
                cur = 1LL * cur * suff[i + 1] % mod;
            }
            
            std::vector<int> suff_row(m);

            for (auto j = m - 1; j >= 0; j--)
            {
                suff_row[j] = grid[i][j];

                if (j + 1 < m)
                {
                    suff_row[j] = 1LL * suff_row[j] * suff_row[j + 1] % mod;
                }
            }

            auto pref_row = 1;

            for (auto j = 0; j < m; j++)
            {
                res[i][j] = pref_row;

                if (j + 1 < m)
                {
                    res[i][j] = 1LL * res[i][j] * suff_row[j + 1] % mod;
                }

                res[i][j] = 1LL * res[i][j] * cur % mod;

                pref_row = 1LL * pref_row * grid[i][j] % mod;
            }        

            pref = 1LL * pref * pref_row % mod;
        }

        return res;
    }
};
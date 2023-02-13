// https://leetcode.com/problems/maximum-rows-covered-by-columns/description/

class Solution
{
public:
    int maximumRows(std::vector<std::vector<int>>& matrix, int numSelect)
    {
        std::vector<bool> probe(std::size(matrix.front()));

        auto res = 0;

        solve(probe, 0, numSelect, std::size(matrix.front()), matrix, res);

        return res;
    }

private:
    void solve(std::vector<bool>& probe, int pos, int k, int n, const std::vector<std::vector<int>>& matrix, int& res)
    {
        if (k == 0)
        {
            const auto n = std::size(matrix);
            const auto m = std::size(matrix.front());

            auto cnt = n;

            for (auto i = 0; i < n; i++)
            {
                for (auto j = 0; j < m; j++)
                {
                    if (matrix[i][j] && !probe[j])
                    {
                        cnt--;
                        break;
                    }
                }
            }

            res = std::max<int>(res, cnt);

            return;
        }

        if (k > n)
        {
            return;
        }

        solve(probe, pos + 1, k, n - 1, matrix, res);

        probe[pos] = true;
        solve(probe, pos + 1, k - 1, n - 1, matrix, res);
        probe[pos] = false;
    }
};
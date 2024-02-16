// https://leetcode.com/problems/largest-magic-square/description/

class Solution
{
public:
    int largestMagicSquare(std::vector<std::vector<int>>& grid)
    {
        const auto n = static_cast<int>(std::size(grid));
        const auto m = static_cast<int>(std::size(grid.front()));

        auto res = -1;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                const auto d = std::min(n - i, m - j);

                for (auto side = 1; side <= d; side++)
                {
                    auto sum = -1;
                    auto magic = true;

                    for (auto r = i; r < i + side && magic; r++)
                    {
                        auto cur = 0;

                        for (auto c = j; c < j + side; c++)
                        {
                            cur += grid[r][c];
                        }

                        if (sum == -1)
                        {
                            sum = cur;
                        }

                        if (cur != sum)
                        {
                            magic = false;
                        }
                    }

                    for (auto c = j; c < j + side && magic; c++)
                    {
                        auto cur = 0;

                        for (auto r = i; r < i + side; r++)
                        {
                            cur += grid[r][c];
                        }

                        if (cur != sum)
                        {
                            magic = false;
                        }
                    }

                    auto diag = 0;

                    for (auto t = 0; t < side; t++)
                    {
                        diag += grid[i + t][j + t];
                    }

                    magic &= diag == sum;

                    auto diag_rev = 0;

                    for (auto t = 0; t < side; t++)
                    {
                        diag_rev += grid[i + t][j + side - t - 1];
                    }

                    magic &= diag_rev == sum;

                    if (magic)
                    {
                        res = std::max(res, side);
                    }
                }
            }
        }

        return res;
    }
};
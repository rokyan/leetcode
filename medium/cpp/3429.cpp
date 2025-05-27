// https://leetcode.com/problems/paint-house-iv/description/

class Solution
{
public:
    long long minCost(int n, const std::vector<std::vector<int>>& cost)
    {
        const auto m = n / 2;

        std::vector<std::vector<std::vector<long long>>> dp(m);

        for (auto i = 0; i < m; i++)
        {
            dp[i].resize(3, std::vector<long long>(3, -1));

            for (auto c1 = 0; c1 < 3; c1++)
            {
                for (auto c2 = 0; c2 < 3; c2++)
                {
                    if (c1 != c2)
                    {
                        auto curCost = 0LL + cost[i][c1] + cost[n - i - 1][c2];
                        auto prevCost = -1LL;

                        if (i > 0)
                        {
                            for (auto c3 = 0; c3 < 3; c3++)
                            {
                                for (auto c4 = 0; c4 < 3; c4++)
                                {
                                    if (c3 != c4 && c1 != c3 && c2 != c4)
                                    {
                                        const auto upd = dp[i - 1][c3][c4];

                                        if (prevCost == -1 || prevCost > upd)
                                        {
                                            prevCost = upd;
                                        }
                                    }
                                }
                            }
                        }

                        if (prevCost != -1)
                        {
                            curCost += prevCost;
                        }

                        if (dp[i][c1][c2] == -1 || dp[i][c1][c2] > curCost)
                        {
                            dp[i][c1][c2] = curCost;
                        }
                    }
                }
            }
        }

        auto res = -1LL;

        for (auto i = 0; i < 3; i++)
        {
            for (auto j = 0; j < 3; j++)
            {
                if (dp.back()[i][j] != -1)
                {
                    if (res == -1 || res > dp.back()[i][j])
                    {
                        res = dp.back()[i][j];
                    } 
                }
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int minimumCost(int m, int n, std::vector<int>& hc, std::vector<int>& vc)
    {
        std::ranges::sort(hc, std::greater<int>{});
        std::ranges::sort(vc, std::greater<int>{});

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, inf));
        dp[0][0] = 0;

        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (i + j > 0)
                {
                    if (i > 0)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + (j + 1) * hc[i - 1]);
                    }

                    if (j > 0)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + (i + 1) * vc[j - 1]);
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
// https://leetcode.com/problems/maximize-total-tastiness-of-purchased-fruits/description/

class Solution
{
public:
    int maxTastiness(const std::vector<int>& price, const std::vector<int>& tastiness,
        int maxAmount, int maxCoupons)
    {
        const auto n = std::size(price);

        std::vector<std::vector<std::vector<int>>> dp(n + 1,
            std::vector<std::vector<int>>(maxAmount + 1, std::vector<int>(maxCoupons + 1)));

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 0; j <= maxAmount; j++)
            {
                for (auto k = 0; k <= maxCoupons; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];

                    if (j >= price[i - 1])
                    {
                        dp[i][j][k] = std::max(dp[i][j][k],
                            dp[i - 1][j - price[i - 1]][k] + tastiness[i - 1]);
                    }

                    if (k > 0 && j >= price[i - 1] / 2)
                    {
                        dp[i][j][k] = std::max(dp[i][j][k],
                            dp[i - 1][j - price[i - 1] / 2][k - 1] + tastiness[i - 1]);
                    }
                }
            }
        }

        return dp[n][maxAmount][maxCoupons];
    }
};
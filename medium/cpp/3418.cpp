// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000 + 7;

public:
    int maximumAmount(const std::vector<std::vector<int>>& coins)
    {
        const auto n = std::size(coins);
        const auto m = std::size(coins.front());

        std::vector<std::vector<std::vector<int>>>
            dp(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(3, -inf)));

        dp[0][1][0] = dp[1][0][0] = 0;

        auto getBest = [&dp](int i, int j, int k)
        {
            if (dp[i - 1][j][k] != -inf && dp[i][j - 1][k] != -inf)
            {
                return max(dp[i - 1][j][k], dp[i][j - 1][k]);
            }

            if (dp[i - 1][j][k] != -inf)
            {
                return dp[i - 1][j][k];
            }

            if (dp[i][j - 1][k] != -inf)
            {
                return dp[i][j - 1][k];
            }

            return -inf;
        };

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= m; j++)
            {
                if (coins[i - 1][j - 1] >= 0)
                {
                    for (auto k = 0; k <= 2; k++)
                    {
                        const auto prev = getBest(i, j, k);

                        if (prev != -inf)
                        {
                            dp[i][j][k] = std::max(dp[i][j][k], coins[i - 1][j - 1] + prev);
                        }
                    }
                }
                else
                {
                    auto prev = getBest(i, j, 0);

                    if (prev != -inf)
                    {
                        dp[i][j][0] = std::max(dp[i][j][0], coins[i - 1][j - 1] + prev);
                    }

                    for (auto k = 1; k <= 2; k++)
                    {
                        prev = getBest(i, j, k - 1);

                        if (prev != -inf)
                        {
                            dp[i][j][k] = std::max(dp[i][j][k], prev);
                        }

                        prev = getBest(i, j, k);

                        if (prev != -inf)
                        {
                            dp[i][j][k] = std::max(dp[i][j][k], coins[i - 1][j - 1] + prev);
                        }
                    }
                }
            }
        }

        return *std::max_element(std::cbegin(dp[n][m]), std::cend(dp[n][m]));
    }
};
// https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/

class Solution
{
public:
    int minimumCoins(std::vector<int>& prices)
    {
        const auto n = std::size(prices);
        std::vector<std::vector<int>> dp(2, std::vector<int>(n, 1000'000'000));
        dp[0][0] = prices[0];

        for (auto i = 1; i < n; i++)
        {
            dp[0][i] = prices[i] + std::min(dp[0][i - 1], dp[1][i - 1]);

            for (auto j = i - 1; j >= 0; j--)
            {
                if (j + j + 1 >= i)
                {
                    dp[1][i] = std::min(dp[1][i], dp[0][j]);
                }
                else
                {
                    break;
                }
            }
        }

        return std::min(dp[0].back(), dp[1].back());
    }
};
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution
{
public:
    int maxProfit(const std::vector<int>& prices)
    {
        const int n = prices.size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(2));

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0];

            if (i > 0)
            {
                dp[i][0] = std::max(dp[i][0], dp[i - 1][1]);
            }

            for (int j = i - 1; j >= 0; j--)
            {
                const int profit = prices[i] - prices[j];

                dp[i][1] = std::max(dp[i][1], profit + (j > 0 ? dp[j - 1][0] : 0));
            }
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }
};
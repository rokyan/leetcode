// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution
{
public:
    int maxProfit(int k, const std::vector<int>& prices)
    {
        const auto n = std::size(prices);

        if (n <= 1)
        {
            return 0;
        }

        std::vector<int> dp(n);

        auto minSoFar = prices[0];

        auto res = 0;

        for (auto i = 1; i < n; i++)
        {
            dp[i] = std::max(dp[i - 1], prices[i] - minSoFar);
            minSoFar = std::min(minSoFar, prices[i]);
            res = std::max(res, dp[i]);
        }

        for (auto j = 2; j <= k; j++)
        {
            const auto start = 2 * (j - 1);
            auto val = dp[start - 1] - prices[start];
            std::vector<int> ndp(n);
            for (auto i = start + 1; i < n; i++)
            {
                ndp[i] = std::max(ndp[i - 1], prices[i] + val);
                val = std::max(val, dp[i - 1] - prices[i]);
                res = std::max(res, ndp[i]);
            }
            dp = std::move(ndp);
        }

        return res;
    }
};
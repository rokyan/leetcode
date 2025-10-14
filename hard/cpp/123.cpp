class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        const int n = std::size(prices);

        if (n == 1)
        {
            return 0;
        }

        std::vector<int> dp(n);

        for (int i = 1, minSoFar = prices[0]; i < n; i++)
        {
            dp[i] = std::max(dp[i - 1], prices[i] - minSoFar);
            minSoFar = std::min(minSoFar, prices[i]);
        }

        int res = dp.back();

        for (int i = n - 2, maxSoFar = prices[n - 1]; i >= 0; i--)
        {
            const int cur = maxSoFar - prices[i];
            res = std::max(res, cur + (i > 0 ? dp[i - 1] : 0));
            maxSoFar = std::max(maxSoFar, prices[i]);
        }

        return res;
    }
};
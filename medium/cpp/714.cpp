// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution
{
public:
    int maxProfit(std::vector<int>& prices, int fee)
    {
        const int n = prices.size();

        if (n == 1)
        {
            return 0;
        }

        int past = -prices[0];
        int res = 0;

        for (int i = 1; i < n; i++)
        {
            const int cur = prices[i] + past - fee;
            past = std::max(past, res - prices[i]);
            res = std::max(res, cur);
        }

        return res;
    }
};
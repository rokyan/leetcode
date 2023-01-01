// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        auto res = 0;

        for (auto i = 1; i < std::size(prices); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                res += prices[i] - prices[i - 1];
            }
        }

        return res;
    }
};
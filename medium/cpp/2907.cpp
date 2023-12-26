class Solution
{
public:
    int maxProfit(std::vector<int>& prices, std::vector<int>& profits)
    {
        const auto n = std::size(prices);

        auto res = -1;

        for (auto i = 1; i + 1 < n; i++)
        {
            auto max_on_left = -1;

            for (auto j = 0; j < i; j++)
            {
                if (prices[j] < prices[i])
                {
                    max_on_left = std::max(max_on_left, profits[j]);
                }
            }

            if (max_on_left == -1)
            {
                continue;
            }

            auto max_on_right = -1;

            for (auto j = i + 1; j < n; j++)
            {
                if (prices[j] > prices[i])
                {
                    max_on_right = std::max(max_on_right, profits[j]);
                }
            }

            if (max_on_right == -1)
            {
                continue;
            }

            res = std::max(res, max_on_left + profits[i] + max_on_right);
        }

        return res;
    }
};
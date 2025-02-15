class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        const auto n = std::size(prices);

        if (n == 1)
        {
            return 0;
        }

        auto min_so_far = prices[0];
        auto res = 0;

        for (auto i = 1; i < n; i++)
        {
            res = std::max(res, prices[i] - min_so_far);
            min_so_far = std::min(min_so_far, prices[i]);
        }

        return res;
    }
};
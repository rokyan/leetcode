// https://leetcode.com/problems/maximum-linear-stock-score/description/

class Solution
{
public:
    long long maxScore(std::vector<int>& prices)
    {
        std::unordered_map<int, long long> sums;

        auto res = 0LL;

        for (auto i = 1; i <= std::size(prices); i++)
        {
            const auto d = prices[i - 1] - i;
            sums[d] += prices[i - 1];
            res = std::max(res, sums[d]);
        }

        return res;
    }
};
// https://leetcode.com/problems/eat-pizzas/description/

class Solution
{
public:
    long long maxWeight(std::vector<int>& pizzas)
    {
        std::ranges::sort(pizzas, std::greater<int>{});

        const int n = std::size(pizzas);

        auto take = n / 4;

        auto res = 0LL;

        for (auto i = 0, times = 0; times < (take + 1) / 2; times++, i++)
        {
            res += pizzas[i];
        }

        for (auto i = (take + 1) / 2, times = 0; times < take / 2; times++, i += 2)
        {
            res += pizzas[i + 1];
        }

        return res;
    }
};
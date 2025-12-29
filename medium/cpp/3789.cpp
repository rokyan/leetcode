https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/

class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        if (costBoth < cost1 + cost2)
        {
            const int take = std::min(need1, need2);
            return 1LL * take * costBoth
                + 1LL * (need1 - take) * std::min(costBoth, cost1)
                + 1LL * (need2 - take) * std::min(costBoth, cost2);
        }

        return 1LL * need1 * std::min(costBoth, cost1) + 1LL * need2 * std::min(costBoth, cost2);
    }
};
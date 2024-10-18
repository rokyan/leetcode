// https://leetcode.com/problems/maximum-number-of-upgradable-servers/description/

class Solution
{
public:
    std::vector<int> maxUpgrades(
        const std::vector<int>& count,
        const std::vector<int>& upgrade,
        const std::vector<int>& sell,
        const std::vector<int>& money)
    {
        const auto n = std::size(count);

        std::vector<int> res(n);

        for (auto i = 0; i < n; i++)
        {
            auto lo = 0;
            auto hi = count[i];

            while (lo < hi)
            {
                const auto mid = lo + (hi - lo + 1) / 2;

                const auto need = 1LL * mid * upgrade[i];
                const auto have = 1LL * (count[i] - mid) * sell[i] + money[i];

                if (need <= have)
                {
                    lo = mid;
                }
                else
                {
                    hi = mid - 1;
                }
            }

            res[i] = lo;
        }

        return res;
    }
};
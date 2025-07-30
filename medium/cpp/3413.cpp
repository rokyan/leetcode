// https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/description/

class Solution
{
public:
    long long maximumCoins(std::vector<std::vector<int>>& coins, int k)
    {
        const int n = std::size(coins);
    
        std::sort(std::begin(coins), std::end(coins),
            [](const auto& lhs, const auto& rhs)
            {
                return lhs[0] < rhs[0];
            }
        );

        std::vector<long long> pref(n);

        for (auto i = 0; i < n; i++)
        {
            pref[i] = 1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1) +
                (i > 0 ? pref[i - 1] : 0);
        }

        auto res = 0LL;

        for (auto r = 0, l = 0; r < n; r++)
        {
            const auto nl = coins[r][1] - k + 1;

            while (nl > coins[l][1])
            {
                l++;
            }

            auto cur = 0LL;

            if (coins[l][0] >= nl)
            {
                cur = 1LL * (coins[l][1] - coins[l][0] + 1) * coins[l][2];
            }
            else
            {
                cur = 1LL * (coins[l][1] - nl + 1) * coins[l][2];
            }

            if (l < r)
            {
                cur += pref[r] - pref[l];
            }

            res = std::max(res, cur);
        }

        for (auto l = n - 1, r = n - 1; l >= 0; l--)
        {
            const auto nr = coins[l][0] + k - 1;

            while (nr < coins[r][0])
            {
                r--;
            }

            auto cur = 0LL;

            if (coins[r][1] <= nr)
            {
                cur = 1LL * (coins[r][1] - coins[r][0] + 1) * coins[r][2];
            }
            else
            {
                cur = 1LL * (nr - coins[r][0] + 1) * coins[r][2];
            }

            if (l < r)
            {
                cur += pref[r - 1] - (l > 0 ? pref[l - 1] : 0);
            }

            res = std::max(res, cur);
        }

        return res;
    }
};
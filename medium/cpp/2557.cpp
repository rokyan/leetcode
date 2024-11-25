// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/description/

class Solution
{
public:
    int maxCount(std::vector<int>& banned, int n, long long maxSum)
    {
        std::sort(std::begin(banned), std::end(banned));

        auto last = std::unique(std::begin(banned), std::end(banned));
        banned.erase(last, std::end(banned));

        const auto m = std::size(banned);

        std::vector<long long> pref(m);

        for (auto i = 0; i < m; i++)
        {
            pref[i] = banned[i];

            if (i > 0)
            {
                pref[i] += pref[i - 1];
            }
        }

        auto lo = 0;
        auto hi = n;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo + 1) / 2;

            auto sum = 1LL * mid * (mid + 1) / 2;

            auto cnt = std::distance(std::cbegin(banned),
                std::upper_bound(std::cbegin(banned), std::cend(banned), mid));

            if (cnt > 0)
            {
                sum -= pref[cnt - 1];
            }

            if (sum <= maxSum)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        auto res = lo - std::distance(std::cbegin(banned),
            std::upper_bound(std::cbegin(banned), std::cend(banned), lo));
        return res;
    }
};
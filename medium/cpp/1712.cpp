// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int waysToSplit(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> pref(n);

        std::partial_sum(std::cbegin(nums), std::cend(nums), std::begin(pref));

        auto res = 0;

        for (auto l = 0, m = 0, r = 0; l + 2 < n; l++)
        {
            m = std::max(m, l + 1);

            while (m + 1 < n && pref[m] - pref[l] < pref[l])
            {
                m++;
            }

            r = std::max(r, m + 1);

            while (r + 1 < n && pref[r] - pref[l] <= pref[n - 1] - pref[r])
            {
                r++;
            }

            r--;

            if (pref[m] - pref[l] >= pref[l] && pref[m] - pref[l] <= pref[n - 1] - pref[r])
            {
                res += r - m + 1;
                res %= mod;
            }
        }

        return res;
    }
};
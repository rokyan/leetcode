// https://leetcode.com/problems/minimum-time-to-break-locks-i/description/

class Solution
{
public:
    int findMinimumTime(const std::vector<int>& strength, int k)
    {
        const int n = std::size(strength);

        auto res = 0;

        auto x = 1;

        for (auto i = 0; i < n; i++)
        {
            res += strength[i] / x + (strength[i] % x != 0);
            x += k;
        }

        std::vector<int> idxs(n);
        std::ranges::iota(idxs, 0);

        do
        {
            auto upd = 0;
            x = 1;

            for (auto i = 0; i < n; i++)
            {
                upd += strength[idxs[i]] / x + (strength[idxs[i]] % x != 0);
                x += k;
            }

            res = std::min(res, upd);
        }
        while (std::next_permutation(std::begin(idxs), std::end(idxs)));

        return res;
    }
};
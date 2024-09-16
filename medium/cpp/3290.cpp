// https://leetcode.com/problems/maximum-multiplication-score/description/

class Solution
{
public:
    long long maxScore(const std::vector<int>& a, const std::vector<int>& b)
    {
        const auto n = std::size(b);

        std::vector<long long> pref(n);
        pref[1] = 1LL * a[0] * b[0] + 1LL * a[1] * b[1];

        auto best = std::max(1LL * a[0] * b[0], 1LL * a[0] * b[1]);

        for (auto i = 2; i < n; i++)
        {
            pref[i] = std::max(pref[i - 1], best + 1LL * a[1] * b[i]);
            best = std::max(best, 1LL * a[0] * b[i]);
        }

        std::vector<long long> suff(n);
        suff[n - 2] = 1LL * a[2] * b[n - 2] + 1LL * a[3] * b[n - 1];

        best = std::max(1LL * a[3] * b[n - 2], 1LL * a[3] * b[n - 1]);

        for (auto i = static_cast<int>(n) - 3; i >= 0; i--)
        {
            suff[i] = std::max(suff[i + 1], best + 1LL * a[2] * b[i]);
            best = std::max(best, 1LL * a[3] * b[i]);
        }

        auto res = 0LL;

        for (auto i = 0; i < 4; i++)
        {
            res += 1LL * a[i] * b[i];
        }

        for (auto i = 1; i + 2 < n; i++)
        {
            res = std::max(res, pref[i] + suff[i + 1]);
        }

        return res;
    }
};
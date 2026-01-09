// https://leetcode.com/problems/number-of-ways-to-paint-sheets/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'000 + 7;

public:
    int numberOfWays(int total, std::vector<int>& limit)
    {
        std::ranges::sort(limit);

        const int n = limit.size();

        std::vector<int> pref(n);
        pref[0] = std::min(limit[0], total - 1);

        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + std::min(limit[i], total - 1);
            pref[i] %= mod;
        }

        int res = 0;

        for (int i = 1; i < n; i++)
        {
            const auto start = limit.cbegin();
            const auto end = std::next(start, i);
            const int rem = std::max(1, total - limit[i]);
            const auto it = std::lower_bound(start, end, rem);

            if (it == end)
            {
                continue;
            }

            const int idx = std::distance(start, it);
            int sum = (pref[i - 1] - (idx > 0 ? pref[idx - 1] : 0) + mod) % mod;
            sum += i - idx;
            sum %= mod;
            sum = (sum - 1LL * rem * (i - idx) % mod + mod) % mod;
            res += sum;
            res %= mod;
        }

        return 1LL * res * 2 % mod;
    }
};
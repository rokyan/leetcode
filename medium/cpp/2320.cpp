// https://leetcode.com/problems/count-number-of-ways-to-place-houses/description/

class Solution
{
public:
    int countHousePlacements(int n)
    {
        const auto mod = 1000 * 1000 * 1000 + 7;

        auto used = 1;
        auto unused = 1;

        for (auto i = 1; i < n; i++)
        {
            const auto next_used = unused;
            const auto next_unused = (used + unused) % mod;

            used = next_used;
            unused = next_unused;
        }

        return 1LL * (used + unused) * (used + unused) % mod;
    }
};
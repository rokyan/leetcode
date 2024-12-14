// https://leetcode.com/problems/bitwise-or-of-all-subsequence-sums/description/

class Solution
{
public:
    long long subsequenceSumOr(std::vector<int>& nums)
    {
        std::array<int, 64> cnt{ 0 };

        for (auto num : nums)
        {
            for (auto bit = 0; bit < 32; bit++)
            {
                if (num & (1 << bit))
                {
                    cnt[bit]++;
                }
            }
        }

        auto res = 0LL;

        for (auto bit = 0, carry = 0; bit < 64; bit++)
        {
            const auto cur = cnt[bit] + carry;

            if (cur > 0)
            {
                res |= 1LL << bit;
            }

            carry += cnt[bit];
            carry /= 2;
        }

        return res;
    }
};
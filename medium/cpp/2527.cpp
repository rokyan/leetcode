// https://leetcode.com/problems/find-xor-beauty-of-array/description/

class Solution
{
public:
    int xorBeauty(std::vector<int>& nums)
    {
        auto n = static_cast<int>(std::size(nums));

        auto res = 0;

        for (auto bit = 0; bit < 32; bit++)
        {
            long long cnt[2] { 0 };

            for (const auto num : nums)
            {
                cnt[(num & (1 << bit)) != 0]++;
            }

            const auto x = (2 * cnt[0] * cnt[1] + cnt[1] * cnt[1]) * cnt[1];

            if (x & 1)
            {
                res |= (1 << bit);
            }
        }

        return res;
    }
};
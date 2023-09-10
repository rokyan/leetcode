// https://leetcode.com/problems/maximum-or/description/

class Solution
{
public:
    long long maximumOr(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::array<int, 64> cnt{ 0 };

        for (auto i = 0; i < n; i++)
        {
            for (auto bit = 0; bit < 32; bit++)
            {
                if ((1 << bit) & nums[i])
                {
                    cnt[bit]++;
                }
            }
        }

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            for (auto bit = 0; bit < 32; bit++)
            {
                if ((1 << bit) & nums[i])
                {
                    cnt[bit]--;
                    cnt[bit + k]++;
                }
            }

            auto upd = 0LL;

            for (auto bit = 0; bit < 64; bit++)
            {
                if (cnt[bit])
                {
                    upd |= 1LL << bit;
                }
            }

            res = std::max(res, upd);

            for (auto bit = 0; bit < 32; bit++)
            {
                if ((1 << bit) & nums[i])
                {
                    cnt[bit]++;
                    cnt[bit + k]--;
                }
            }
        }

        return res;
    }
};
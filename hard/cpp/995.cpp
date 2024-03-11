// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

class Solution
{
public:
    int minKBitFlips(std::vector<int>& nums, int k)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> axor(n);

        auto res = 0;
        auto rs = 0;

        for (auto i = 0; i + k - 1 < n; i++)
        {
            rs ^= axor[i];
            const auto val = nums[i] ^ rs;

            if (val == 0)
            {
                res++;

                rs ^= 1;

                if (i + k < n)
                {
                    axor[i + k] ^= 1;
                }
            }
        }

        for (auto i = n - k + 1; i < n; i++)
        {
            rs ^= axor[i];
            if (nums[i] ^ rs == 0)
            {
                return -1;
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/

class Solution
{
public:
    std::vector<int> smallestSubarrays(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> last_with_bit(32, -1);

        std::vector<int> res(n);

        for (auto pos = n - 1; pos >= 0; pos--)
        {
            for (auto bit = 0; bit < 32; bit++)
            {
                if ((1 << bit) & nums[pos])
                {
                    last_with_bit[bit] = pos;
                }
            }

            auto len = 1;

            for (auto bit = 0; bit < 32; bit++)
            {
                if (last_with_bit[bit] != -1)
                {
                    len = std::max(len, last_with_bit[bit] - pos + 1);
                }
            }

            res[pos] = len;
        }

        return res;
    }
};
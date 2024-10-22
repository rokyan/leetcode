// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/

class Solution
{
public:
    int minimumSubarrayLength(const std::vector<int>& nums, int k)
    {
        if (k == 0)
        {
            return 1;
        }

        std::array<int, 32> freq{ 0 };

        auto res = -1;

        for (auto l = 0, r = 0, s = 0; l < std::size(nums); l++)
        {
            while (r < std::size(nums) && s < k)
            {
                s |= nums[r];

                for (auto bit = 0; bit < 32; bit++)
                {
                    if (nums[r] & (1 << bit))
                    {
                        freq[bit]++;
                    }
                }

                r++;
            }

            if (s >= k)
            {
                res = res == -1 ? r - l : std::min(res, r - l);
            }

            for (auto bit = 0; bit < 32; bit++)
            {
                if (nums[l] & (1 << bit))
                {
                    if (freq[bit]-- == 1)
                    {
                        s ^= (1 << bit);
                    }
                }
            }
        }

        return res;
    }
};
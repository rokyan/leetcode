// https://leetcode.com/problems/longest-semi-repeating-subarray/description/

class Solution
{
public:
    int longestSubarray(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> freq;
        auto rep = 0;
        auto res = 0;

        for (auto l = 0, r = 0; r < std::size(nums); r++)
        {
            if (freq[nums[r]]++ == 1)
            {
                rep++;
            }

            while (rep > k)
            {
                if (--freq[nums[l++]] == 1)
                {
                    rep--;
                }
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
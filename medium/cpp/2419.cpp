// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

class Solution
{
public:
    int longestSubarray(std::vector<int>& nums)
    {
        const auto max_val = *std::max_element(std::begin(nums), std::end(nums));

        auto res = 0;
        auto len = 0;

        for (auto pos = 0; pos < std::size(nums); pos++)
        {
            if (nums[pos] == max_val)
            {
                len++;
            }
            else
            {
                res = std::max(res, len);
                len = 0;
            }
        }

        return std::max(res, len);
    }
};
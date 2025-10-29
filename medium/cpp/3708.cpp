// https://leetcode.com/problems/longest-fibonacci-subarray/description/

class Solution
{
public:
    int longestSubarray(const std::vector<int>& nums)
    {
        int res = 2;
        int len = 2;

        const int n = std::size(nums);

        for (int i = 2; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + nums[i - 2])
            {
                len++;
            }
            else
            {
                res = std::max(res, len);
                len = 2;
            }
        }

        return std::max(res, len);
    }
};
// https://leetcode.com/problems/longest-alternating-subarray-after-removing-at-most-one-element/description/

class Solution
{
public:
    int longestAlternating(const std::vector<int>& nums)
    {
        const int n = nums.size();

        std::vector<std::vector<int>> prefDp(2, std::vector<int>(n));

        int res = 1;

        for (int i = 0; i < n; i++)
        {
            prefDp[0][i] = prefDp[1][i] = 1;

            if (i > 0 && nums[i] > nums[i - 1])
            {
                prefDp[0][i] = 1 + prefDp[1][i - 1];
                res = std::max(res, prefDp[0][i]);
            }

            if (i > 0 && nums[i] < nums[i - 1])
            {
                prefDp[1][i] = 1 + prefDp[0][i - 1];
                res = std::max(res, prefDp[1][i]);
            }
        }

        std::vector<std::vector<int>> suffDp(2, std::vector<int>(n));

        for (int i = n - 1; i >= 0; i--)
        {
            suffDp[0][i] = suffDp[1][i] = 1;

            if (i + 1 < n && nums[i] > nums[i + 1])
            {
                suffDp[0][i] = 1 + suffDp[1][i + 1];
                res = std::max(res, suffDp[0][i]);
            }

            if (i + 1 < n && nums[i] < nums[i + 1])
            {
                suffDp[1][i] = 1 + suffDp[0][i + 1];
                res = std::max(res, suffDp[1][i]);
            }
        }

        for (int i = 1; i + 1 < n; i++)
        {
            if (nums[i - 1] < nums[i + 1])
            {
                res = std::max(res, prefDp[1][i - 1] + suffDp[0][i + 1]);
            }

            if (nums[i - 1] > nums[i + 1])
            {
                res = std::max(res, prefDp[0][i - 1] + suffDp[1][i + 1]);
            }
        }

        return res;
    }
};
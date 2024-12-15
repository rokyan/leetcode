// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

class Solution
{
public:
    int maxIncreasingSubarrays(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> len(n, 1);

        for (auto i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                len[i] += len[i - 1];
            }
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            res = std::max(res, len[i] / 2);

            const auto prev = i - len[i];

            if (prev >= 0)
            {
                res = std::max(res, std::min(len[prev], len[i]));
            }
        }

        return res;
    }
};
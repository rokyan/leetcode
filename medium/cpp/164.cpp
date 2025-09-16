// https://leetcode.com/problems/maximum-gap/description/

class Solution
{
public:
    int maximumGap(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        if (n < 2)
        {
            return 0;
        }

        std::ranges::sort(nums);

        auto res = nums[1] - nums[0];

        for (auto i = 2; i < n; i++)
        {
            res = std::max(res, nums[i] - nums[i - 1]);
        }

        return res;
    }
};
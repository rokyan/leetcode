// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/description/

class Solution
{
public:
    int maximumTop(std::vector<int>& nums, int k)
    {
        if (k == 0)
        {
            return nums[0];
        }

        if (k == 1)
        {
            return std::size(nums) > 1 ? nums[1] : -1;
        }

        const auto n = static_cast<int>(std::size(nums));

        if (n == 1)
        {
            return k % 2 == 0 ? nums[0] : -1;
        }

        auto res = nums[0];

        for (auto i = 1; i < std::min(n, k - 1); i++)
        {
            res = std::max(res, nums[i]);
        }

        if (k < n)
        {
            res = std::max(res, nums[k]);
        }

        return res;
    }
};
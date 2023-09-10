// https://leetcode.com/problems/first-missing-positive/description/

class Solution
{
public:
    int firstMissingPositive(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        for (auto i = 0; i < n; i++)
        {
            if (nums[i] <= 0 || nums[i] > n + 1)
            {
                nums[i] = n + 2;
            }
        }

        for (auto i = 0; i < n; i++)
        {
            if (std::abs(nums[i]) <= n && nums[std::abs(nums[i]) - 1] > 0)
            {
                nums[std::abs(nums[i]) - 1] *= -1;
            }
        }

        for (auto i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};
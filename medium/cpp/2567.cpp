// https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/

class Solution
{
public:
    int minimizeSum(vector<int>& nums)
    {
        const auto n = std::size(nums);

        if (n <= 3)
        {
            return 0;
        }

        std::sort(std::begin(nums), std::end(nums));

        return std::min(nums[n - 2] - nums[1], std::min(nums[n - 1] - nums[2], nums[n - 3] - nums[0]));
    }
};
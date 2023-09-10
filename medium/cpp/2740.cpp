// https://leetcode.com/problems/find-the-value-of-the-partition/description/

class Solution
{
public:
    int findValueOfPartition(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));

        auto res = nums[1] - nums[0];

        for (auto i = 2; i < std::size(nums); i++)
        {
            res = std::min(res, nums[i] - nums[i - 1]);
        }

        return res;
    }
};
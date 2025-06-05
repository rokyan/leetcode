// https://leetcode.com/problems/make-array-non-decreasing/description/

class Solution
{
public:
    int maximumPossibleSize(const std::vector<int>& nums)
    {
        auto last = 0;
        auto res = 1;

        for (auto i = 1; i < std::size(nums); i++)
        {
            if (nums[i] >= nums[last])
            {
                res++;
                last = i;
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

#include <ranges>

class Solution
{
public:
    int maxDistinctElements(std::vector<int>& nums, int k)
    {
        std::ranges::sort(nums);

        auto res = 1;
        auto last = nums[0] - k;

        for (auto i = 1; i < std::size(nums); i++)
        {
            if (last < nums[i] - k)
            {
                res++;
                last = nums[i] - k;
            }
            else if (last < nums[i] + k)
            {
                res++;
                last++;
            }
        }

        return res;
    }
};
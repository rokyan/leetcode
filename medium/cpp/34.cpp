// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        auto [first, last] = std::equal_range(std::begin(nums), std::end(nums), target);
        
        if (first == std::cend(nums) || target != *first)
        {
            return { -1, -1 };
        }
        
        return { static_cast<int>(std::distance(std::begin(nums), first)), static_cast<int>(std::distance(std::begin(nums), --last)) };
    }
};
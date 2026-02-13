// https://leetcode.com/problems/final-element-after-subarray-deletions/description/

class Solution
{
public:
    int finalElement(std::vector<int>& nums)
    {
        return std::max(nums.front(), nums.back());
    }
};
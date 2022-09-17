// https://leetcode.com/problems/sort-an-array/

class Solution
{
public:
    std::vector<int> sortArray(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        return nums;
    }
};
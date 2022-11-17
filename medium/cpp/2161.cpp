// https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution
{
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot)
    {
        auto it = std::stable_partition(std::begin(nums), std::end(nums), [pivot](auto e) { return e < pivot; });
        
        std::stable_partition(it, std::end(nums), [pivot](auto e) { return e == pivot; });
        
        return nums;
    }
};
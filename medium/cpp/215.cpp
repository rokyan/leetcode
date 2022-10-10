// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution
{
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        std::nth_element(std::begin(nums), std::begin(nums) + k - 1, std::end(nums), std::greater<>());
        return nums[k - 1];
    }
};
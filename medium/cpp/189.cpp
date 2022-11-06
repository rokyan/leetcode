// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    void rotate(std::vector<int>& nums, int k) 
    {
        k %= std::size(nums);
        
        std::reverse(std::begin(nums), std::end(nums));
        std::reverse(std::begin(nums), std::begin(nums) + k);
        std::reverse(std::begin(nums) + k, std::end(nums));
    }
};
// https://leetcode.com/problems/next-permutation/

class Solution
{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        std::next_permutation(std::begin(nums), std::end(nums));
    }
};
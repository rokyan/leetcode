// https://leetcode.com/problems/circular-permutation-in-binary-representation/

class Solution
{
public:
    std::vector<int> circularPermutation(int n, int start)
    {
        std::vector<int> nums(1 << n);
        
        for (int i = 0; i < (1 << n); i++)
        {
            nums[i] = i ^ (i >> 1);
        }
        
        auto pos = std::find(std::begin(nums), std::end(nums), start);        
        std::rotate(std::begin(nums), pos, std::end(nums));
        
        return nums;
    }
};
// https://leetcode.com/problems/gray-code/description/

class Solution
{
public:
    std::vector<int> grayCode(int n)
    {
        std::vector<int> nums(1 << n);
        
        for (int i = 0; i < (1 << n); i++)
        {
            nums[i] = i ^ (i >> 1);
        }
        
        return nums;
    }
};
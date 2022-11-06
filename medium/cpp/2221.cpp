// https://leetcode.com/problems/find-triangular-sum-of-an-array/

class Solution
{
public:
    int triangularSum(vector<int>& nums)
    {      
        auto n = std::size(nums);
        
        while (n > 1)
        {
            for (std::size_t i = 0; i + 1 < n; i++)
            {
                nums[i] += nums[i + 1];
                
                if (nums[i] >= 10)
                {
                    nums[i] %= 10;
                }
            }
            
            n--;
        }
        
        return nums[0];
    }
};
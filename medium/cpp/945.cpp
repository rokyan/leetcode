// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

class Solution
{
public:
    int minIncrementForUnique(vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        int ans = 0;
        int prev = nums[0];
        
        for (int i = 1; i < std::size(nums); i++)
        {
            if (nums[i] <= prev)
            {
                ans += prev + 1 - nums[i];
                nums[i] = prev + 1;
            }
            
            prev = nums[i];
        }
        
        return ans;
    }
};
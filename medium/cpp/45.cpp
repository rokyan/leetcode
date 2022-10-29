// https://leetcode.com/problems/jump-game-ii/

class Solution
{
public:
    int jump(std::vector<int>& nums)
    {
        std::vector<int> dp(std::size(nums), std::size(nums) + 1);
        
        std::size_t left = 0;
        std::size_t right = 1;
        
        dp[left] = 0;
        
        while (left < right)
        {           
            while (right < std::size(nums) && right - left <= nums[left])
            {
                dp[right++] = dp[left] + 1;
            }
            
            left++;
        }
        
        return dp.back();    
    }
};
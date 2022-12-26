// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution
{
public:
    int minSubArrayLen(int s, std::vector<int>& nums)
    {  
        auto lf = 0;
        auto rg = 0;
    
        auto sum = 0;    
        auto ans = 0;
    
        while (lf < std::size(nums))
        {
            while (rg < std::size(nums) && sum < s)
            {
                sum += nums[rg++];
            }
    
            if (sum < s)
            {
                break;
            }

            ans = (ans == 0) ? (rg - lf) : std::min(ans, rg - lf);
    
            sum -= nums[lf++];
        }
    
        return ans;
    }
};
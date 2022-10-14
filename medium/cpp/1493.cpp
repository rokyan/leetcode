// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution
{
public:
    int longestSubarray(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));
        
        auto balance = 0;
        auto ans = 0;
        
        for (auto right = 0, left = 0; right < n; right++)
        {
            if (nums[right] == 0)
            {
                balance++;
            }
            
            while (left < right && balance > 1)
            {
                if (nums[left++] == 0)
                {
                    balance--;
                }
            }
            
            ans = std::max(ans, right - left);
        }
        
        return ans;
    }
};
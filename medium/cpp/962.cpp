// https://leetcode.com/problems/maximum-width-ramp/

class Solution
{
public:
    int maxWidthRamp(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        std::vector<std::pair<int, int>> nums_with_pos(n);
        
        for (std::size_t i = 0; i < n; i++)
        {
            nums_with_pos[i] = { nums[i], i };
        }
        
        std::sort(std::begin(nums_with_pos), std::end(nums_with_pos));
        
        auto min_pos = nums_with_pos.front().second;
        
        int ans = 0;
        
        for (std::size_t i = 1; i < n; i++)
        {
            if (nums_with_pos[i].second > min_pos)
            {
                ans = std::max(ans, nums_with_pos[i].second - min_pos);
            }
            else
            {
                min_pos = nums_with_pos[i].second;
            }
        }
         
        return ans;
    }
};
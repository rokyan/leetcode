// https://leetcode.com/problems/container-with-most-water/

class Solution
{
public:
    int maxArea(std::vector<int>& height)
    {
        int left = 0;
        int right = std::size(height) - 1;
        int vol = 0;
        
        while (left < right)
        {
            const int cur_height = std::min(height[left], height[right]);
            const int cur_vol = cur_height * (right - left);
            vol = std::max(vol, cur_vol);
            
            while (left < right && height[left] <= cur_height)
            {
                left++;
            }
            
            while (left < right && height[right] <= cur_height)
            {
                right--;
            }
        }
        
        return vol;
    }
};
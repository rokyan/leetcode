// https://leetcode.com/problems/jump-game/

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        std::vector<int> visited(std::size(nums));
        
        std::size_t left = 0;
        std::size_t right = 1;
        
        visited[left] = true;
        
        while (left < right && !visited.back())
        {           
            while (visited[left] && right < std::size(nums) && right - left <= nums[left])
            {
                visited[right++] = true;
            }
            
            left++;
        }
        
        return visited.back();
    }
};
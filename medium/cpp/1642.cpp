// https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution
{
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders)
    {
        const auto n = std::size(heights);
        
        if (n == 1)
        {
            return 0;
        }
        
        std::vector<int> diff(n - 1);
        
        for (std::size_t i = 0; i + 1 < n; i++)
        {
            diff[i] = heights[i + 1] > heights[i] ? heights[i + 1] - heights[i] : 0;
        }
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> p_queue;
        
        int ans = 0;
        
        for (std::size_t i = 0; i + 1 < n; i++)
        {
            if (diff[i] == 0)
            {
                ans++;
                continue;
            }
            
            p_queue.push(diff[i]);
            
            if (std::size(p_queue) <= ladders)
            {
                ans++;
                continue;
            }
            
            const auto min_diff = p_queue.top();
            p_queue.pop();
            
            if (bricks >= min_diff)
            {
                bricks -= min_diff;
                ans++;
            }
            else
            {
                break;
            }
        }
        
        return ans;
    }
};
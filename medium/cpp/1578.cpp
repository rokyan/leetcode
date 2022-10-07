// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution
{
public:
    int minCost(std::string colors, std::vector<int>& neededTime)
    {
        int max_time = neededTime.front();
        int tot_time = neededTime.front();
        
        int ans = 0;
        
        for (std::size_t pos = 1; pos < std::size(colors); pos++)
        {
            if (colors[pos] == colors[pos - 1])
            {
                max_time = std::max(max_time, neededTime[pos]);
                tot_time += neededTime[pos];
            }
            else
            {
                ans += tot_time - max_time;
                max_time = tot_time = neededTime[pos];
            }
        }
        
        ans += tot_time - max_time;
        
        return ans;
    }
};
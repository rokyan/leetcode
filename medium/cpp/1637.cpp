// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

class Solution
{
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points)
    {
        std::sort(begin(points), end(points), [](auto&& p1, auto&& p2)
        {
           return p1[0] < p2[0]; 
        });
        
        int ans = 0;
        
        for (int i = 1; i < size(points); i++)
        {
            const int dist = points[i][0] - points[i - 1][0];
            
            if (dist > ans)
            {
                ans = dist;
            }
        }
        
        return ans;
    }
};
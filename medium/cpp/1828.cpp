// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution
{
public:
    std::vector<int> countPoints(std::vector<std::vector<int>>& points, std::vector<std::vector<int>>& queries)
    {
        std::vector<int> answer;
        answer.reserve(std::size(queries));
        
        for (const auto& query : queries)
        {
            const auto x = query[0];
            const auto y = query[1];
            const auto r = query[2];
            
            auto count = 0;
            
            for (const auto& point : points)
            {
                const auto px = point[0];
                const auto py = point[1];
                
                if ((px - x) * (px - x) + (py - y) * (py - y) <= r * r)
                {
                    count++;
                }
            }
            
            answer.push_back(count);
        }
        
        return answer;
    }
};
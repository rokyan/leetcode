// https://leetcode.com/problems/brick-wall/

class Solution
{
public:
    int leastBricks(std::vector<std::vector<int>>& wall)
    {
        const auto n = std::size(wall);
        
        std::unordered_map<int, int> counts;
        
        for (const auto& row : wall)
        {
            auto pos = 0;
            
            for (auto i = 0; i + 1 < std::size(row); i++)
            {
                pos += row[i];
                counts[pos]++;
            }
        }
        
        auto ans = n;
        
        for (const auto& entry : counts)
        {
            const auto pos = entry.first;
            const auto edges = entry.second;
            
            ans = std::min(ans, n - edges);
        }
        
        return ans;
    }
};
// https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution
{
public:
    int equalPairs(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        
        std::map<std::vector<int>, int> cnt;
        
        std::vector<int> acc;
        acc.reserve(n);
        
        for (std::size_t i = 0; i < n; i++)
        {
            acc.clear();
            
            for (std::size_t j = 0; j < n; j++)
            {
                acc.push_back(grid[i][j]);
            }
            
            cnt[acc]++;
        }
        
        auto pairs = 0;
        
        for (std::size_t j = 0; j < n; j++)
        {
            acc.clear();
            
            for (std::size_t i = 0; i < n; i++)
            {
                acc.push_back(grid[i][j]);
            }
            
            const auto it = cnt.find(acc);
            
            if (it != std::end(cnt))
            {
                pairs += it->second;
            }
        }
        
        return pairs;
    }
};
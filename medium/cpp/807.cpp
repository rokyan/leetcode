// https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

class Solution
{
public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid)
    {
        const auto sz = std::size(grid);

        std::vector<int> horizontal(sz), vertical(sz);
        
        for (std::size_t i = 0; i < sz; i++)
        {
            for (std::size_t j = 0; j < sz; j++)
            {
                horizontal[i] = std::max(horizontal[i], grid[i][j]);
                vertical[j] = std::max(vertical[j], grid[i][j]);
            }
        }
        
        auto ans = 0;
        
        for (std::size_t i = 0; i < sz; i++)
        {
            for (std::size_t j = 0; j < sz; j++)
            {
                const auto h = std::min(horizontal[i], vertical[j]);
                
                if (grid[i][j] < h)
                {
                    ans += h - grid[i][j];
                }
            }
        }
        
        return ans;
    }
};
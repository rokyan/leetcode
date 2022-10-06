// https://leetcode.com/problems/minimum-path-cost-in-a-grid/

class Solution
{
public:
    int minPathCost(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& moveCost)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<int> dp_prev(grid.front());
        std::vector<int> dp_curr(m);
        
        for (std::size_t i = 1; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                for (std::size_t k = 0; k < m; k++)
                {
                    const auto val = dp_prev[j] + moveCost[grid[i - 1][j]][k] + grid[i][k];
                    
                    dp_curr[k] = dp_curr[k] == 0 ? val : std::min(dp_curr[k], val);
                }
            }
            
            dp_prev = dp_curr;
            
            std::fill(std::begin(dp_curr), std::end(dp_curr), 0);
        }
        
        return *std::min_element(std::begin(dp_prev), std::end(dp_prev));
    }
};
// https://leetcode.com/problems/maximum-sum-of-an-hourglass/

class Solution
{
public:
    int maxSum(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        auto ans = 0;
        
        for (auto i = 0; i + 2 < n; i++)
        {
            for (auto j = 0; j + 2 < m; j++)
            {
                ans = std::max(ans, calc(grid, i, j));
            }
        }
        
        return ans;
    }
    
private:
    int calc(const std::vector<std::vector<int>>& grid, std::size_t i, std::size_t j)
    {
        auto s = 0;
        
        for (auto ii = i; ii < i + 3; ii++)
        {
            for (auto jj = j; jj < j + 3; jj++)
            {
                if (ii == i + 1 && (jj == j || jj == j + 2))
                {
                    continue;
                }
                
                s += grid[ii][jj];
            }
        }
        
        return s;
    }
};
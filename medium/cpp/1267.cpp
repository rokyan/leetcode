// https://leetcode.com/problems/count-servers-that-communicate/

class Solution
{
public:
    int countServers(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<int> cnt_row(n);
        std::vector<int> cnt_col(m);
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    cnt_row[i]++;
                    cnt_col[j]++;
                }
            }
        }
        
        auto ans = 0;
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (grid[i][j] && (cnt_row[i] > 1 || cnt_col[j] > 1))
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
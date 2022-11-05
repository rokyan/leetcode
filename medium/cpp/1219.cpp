// https://leetcode.com/problems/path-with-maximum-gold/

class Solution
{
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<std::vector<int>> visited(n, std::vector<int>(m));
        
        auto answer = 0;
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (grid[i][j] > 0)
                {
                   answer = std::max(answer, solve(i, j, n, m, grid, visited)); 
                }
            }
        }
        
        return answer;
    }
    
private:
    int solve(std::size_t i, std::size_t j, std::size_t n, std::size_t m,
        const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited)
    {
        visited[i][j] = true;
        
        auto sum = 0;
        
        if (i > 0 && grid[i - 1][j] > 0 && !visited[i - 1][j])
        {
            sum = std::max(sum, solve(i - 1, j, n, m, grid, visited));
        }
        
        if (i + 1 < n && grid[i + 1][j] > 0 && !visited[i + 1][j])
        {
            sum = std::max(sum, solve(i + 1, j, n, m, grid, visited));
        }
        
        if (j > 0 && grid[i][j - 1] > 0 && !visited[i][j - 1])
        {
            sum = std::max(sum, solve(i, j - 1, n, m, grid, visited));
        }
        
        if (j + 1 < m && grid[i][j + 1] > 0 && !visited[i][j + 1])
        {
            sum = std::max(sum, solve(i, j + 1, n, m, grid, visited));
        }
        
        visited[i][j] = false;
        
        return grid[i][j] + sum;
    }
};
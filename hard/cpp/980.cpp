// https://leetcode.com/problems/unique-paths-iii/description/

class Solution
{   
public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        auto cnt = 0;
        
        for (auto row = 0; row < n; row++)
        {
            for (auto col = 0; col < m; col++)
            {
                if (grid[row][col] != -1)
                {
                    cnt++;
                }
            }
        }
        
        for (auto row = 0; row < n; row++)
        {
            for (auto col = 0; col < m; col++)
            {
                if (grid[row][col] == 1)
                {
                    std::vector<std::vector<int>> visited(n, std::vector<int>(m));                
                
                    return solve(row, col, cnt, n, m, grid, visited, 1);   
                }
            }
        }
        
        return -1;
    }
    
private:
    int solve(int row, int col, int cnt, int n, int m,
        const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited, int path_len)
    {
        if (path_len == cnt)
        {
            return grid[row][col] == 2;
        }
        
        int tot = 0;
        
        visited[row][col] = true;
        
        if (row > 0 && !visited[row - 1][col] && grid[row - 1][col] != -1)
        {
            tot += solve(row - 1, col, cnt, n, m, grid, visited, path_len + 1);
        }
        
        if (row + 1 < n && !visited[row + 1][col] && grid[row + 1][col] != -1)
        {
            tot += solve(row + 1, col, cnt, n, m, grid, visited, path_len + 1);
        }
        
        if (col > 0 && !visited[row][col - 1] && grid[row][col - 1] != -1)
        {
            tot += solve(row, col - 1, cnt, n, m, grid, visited, path_len + 1);
        }
        
        if (col + 1 < m && !visited[row][col + 1] && grid[row][col + 1] != -1)
        {
            tot += solve(row, col + 1, cnt, n, m, grid, visited, path_len + 1);
        }
        
        visited[row][col] = false;
        
        return tot;
    }
};
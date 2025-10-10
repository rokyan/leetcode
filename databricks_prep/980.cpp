class Solution
{   
public:
    int uniquePathsIII(const std::vector<std::vector<int>>& grid)
    {
        const int n = std::size(grid);
        const int m = std::size(grid.front());
        
        int cnt = 0;
        
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] != -1)
                {
                    cnt++;
                }
            }
        }
        
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
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
        const std::vector<std::vector<int>>& grid,
        std::vector<std::vector<int>>& visited,
        int path_len)
    {
        if (row < 0 || row == n || col < 0 || col == m || visited[row][col] || grid[row][col] == -1)
        {
            return 0;
        }

        if (grid[row][col] == 2)
        {
            return path_len == cnt;
        }
        
        int tot = 0;
        
        visited[row][col] = true;
        
        tot += solve(row - 1, col, cnt, n, m, grid, visited, path_len + 1);    
        tot += solve(row + 1, col, cnt, n, m, grid, visited, path_len + 1);    
        tot += solve(row, col - 1, cnt, n, m, grid, visited, path_len + 1);    
        tot += solve(row, col + 1, cnt, n, m, grid, visited, path_len + 1);
        
        visited[row][col] = false;
        
        return tot;
    }
};
// https://leetcode.com/problems/coloring-a-border/

class Solution
{
public:
    std::vector<std::vector<int>> colorBorder(std::vector<std::vector<int>>& grid, int row, int col, int color)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<std::vector<int>> visited(n, std::vector<int>(m));
        
        dfs(row, col, n, m, row, col, grid, visited);
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (visited[i][j])
                {
                    auto cnt = 0;
                    
                    cnt += i > 0 && visited[i - 1][j];
                    cnt += i + 1 < n && visited[i + 1][j];
                    cnt += j > 0 && visited[i][j - 1];
                    cnt += j + 1 < m && visited[i][j + 1];
                    
                    if (cnt < 4)
                    {
                        grid[i][j] = color;
                    }
                }
            }
        }
        
        return grid;
    }
    
private:
    void dfs(int i, int j, int n, int m, int row, int col,
        const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited)
    {
        if (i < 0 || i == n || j < 0 || j == m || visited[i][j] || grid[i][j] != grid[row][col])
        {
            return;
        }
        
        visited[i][j] = true;
        
        dfs(i + 1, j, n, m, row, col, grid, visited);
        dfs(i - 1, j, n, m, row, col, grid, visited);
        dfs(i, j + 1, n, m, row, col, grid, visited);
        dfs(i, j - 1, n, m, row, col, grid, visited);
    }
};
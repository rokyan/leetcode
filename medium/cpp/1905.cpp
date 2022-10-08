// https://leetcode.com/problems/count-sub-islands/

class Solution
{
public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2)
    {
        const auto n = std::size(grid1);
        const auto m = std::size(grid1.front());
        
        std::vector<std::vector<int>> component(n, std::vector<int>(m));
        
        int cc = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!component[i][j] && grid1[i][j])
                {
                    dfs1(i, j, n, m, ++cc, grid1, component);
                }
            }
        }
        
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
        
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid2[i][j])
                {
                    if (dfs2(i, j, n, m, component[i][j], grid2, visited, component) && component[i][j])
                    {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
    
private:
    void dfs1(int i, int j, int n, int m, int cc, const std::vector<std::vector<int>>& grid,
        std::vector<std::vector<int>>& component)
    {       
        if (i < 0 || i == n || j < 0 || j == m)
        {
            return;
        }
        
        if (component[i][j])
        {
            return;
        }
        
        if (grid[i][j] == 0)
        {
            return;
        }
        
        component[i][j] = cc;
        
        dfs1(i - 1, j, n, m, cc, grid, component);
        dfs1(i + 1, j, n, m, cc, grid, component);
        dfs1(i, j + 1, n, m, cc, grid, component);
        dfs1(i, j - 1, n, m, cc, grid, component);
    }
    
    bool dfs2(int i, int j, int n, int m, int cc, const std::vector<std::vector<int>>& grid,
        std::vector<std::vector<bool>>& visited, const std::vector<std::vector<int>>& component)
    {
        if (i < 0 || i == n || j < 0 || j == m)
        {
            return true;
        }
        
        if (visited[i][j])
        {
            return true;
        }
        
        if (grid[i][j] == 0)
        {
            return true;
        }
        
        visited[i][j] = true;
        
        bool res = true;
        
        res &= dfs2(i - 1, j, n, m, cc, grid, visited, component);
        res &= dfs2(i + 1, j, n, m, cc, grid, visited, component);
        res &= dfs2(i, j + 1, n, m, cc, grid, visited, component);
        res &= dfs2(i, j - 1, n, m, cc, grid, visited, component);
            
        return res && component[i][j] == cc;
    }
};
// https://leetcode.com/problems/number-of-closed-islands/

class Solution
{
public:
    int closedIsland(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
        
        std::queue<std::pair<int, int>> q;
        
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 0)
            {
                visited[i][0] = true;
                q.push({ i, 0 });
            }
            
            if (grid[i][m - 1] == 0)
            {
                visited[i][m - 1] = true;
                q.push({ i, m - 1 });
            }
        }
        
        for (int j = 1; j + 1 < m; j++)
        {
            if (grid[0][j] == 0)
            {
                visited[0][j] = true;
                q.push({ 0, j });
            }
            
            if (grid[n - 1][j] == 0)
            {
                visited[n - 1][j] = true;
                q.push({ n - 1, j });
            }
        }
        
        bfs(n, m, q, visited, grid);
        
        int cnt = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({ i, j });
                    bfs(n, m, q, visited, grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
private:
    void bfs(std::size_t n, std::size_t m, std::queue<std::pair<int, int>> q,
             std::vector<std::vector<bool>>& visited, const std::vector<std::vector<int>>& grid)
    {
        int di[4] = { 1, 0, -1, 0 };
        int dj[4] = { 0, -1, 0, 1 };
        
        while (!q.empty())
        {
            const auto state = q.front();
            q.pop();
            
            for (int d = 0; d < 4; d++)
            {
                const auto i = state.first + di[d];
                const auto j = state.second + dj[d];
                
                if (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({ i, j });
                }
            }
        }
    }
};
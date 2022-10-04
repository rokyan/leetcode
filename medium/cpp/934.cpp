// https://leetcode.com/problems/shortest-bridge/

class Solution
{
private:
    static constexpr auto INF = 1001 * 1001;
    
public:
    int shortestBridge(vector<vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, INF));
        
        bool colored = false;
        
        for (int i = 0; i < n && !colored; i++)
        {
            for (int j = 0; j < m && !colored; j++)
            {
                if (grid[i][j] == 1)
                {
                    color_island(i, j, n, m, grid, dist);
                    colored = true;
                }
            }
        }
        
        std::queue<std::pair<int, int>> q;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dist[i][j] == 0)
                {
                    q.push({ i, j });
                }
            }
        }
        
        int di[4] = { 1, 0, -1, 0 };
        int dj[4] = { 0, -1, 0, 1 };
        
        int ans = INF;
        
        while (!q.empty())
        {
            const auto pos = q.front();
            q.pop();
                        
            for (int d = 0; d < 4; d++)
            {
                const int i = pos.first + di[d];
                const int j = pos.second + dj[d];
                
                if (i >= 0 && i < n && j >= 0 && j < m && dist[i][j] == INF)
                {  
                    dist[i][j] = dist[pos.first][pos.second] + 1;
                    
                    if (grid[i][j] == 1)
                    {
                        ans = std::min(ans, dist[i][j]);
                    }
                    else
                    {
                        q.push({ i, j });
                    }
                }
            }
        }
        
        return ans - 1;
    }
    
private:
    void color_island(int i, int j, int n, int m,
        const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& dist)
    {       
        if (i < 0 || i == n || j < 0 || j == m || !grid[i][j] || dist[i][j] == 0)
        {
            return;
        }
        
        dist[i][j] = 0;
        
        color_island(i + 1, j, n, m, grid, dist);
        color_island(i - 1, j, n, m, grid, dist);
        color_island(i, j + 1, n, m, grid, dist);
        color_island(i, j - 1, n, m, grid, dist);
    }
};
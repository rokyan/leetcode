// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution
{
public:
    int maxDistance(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
        
        std::queue<std::pair<int, int>> cells;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    cells.push({ i, j });
                    dist[i][j] = 0;
                }
            }
        }
        
        int di[4] = { 1, 0, -1, 0 };
        int dj[4] = { 0, -1, 0, 1 };
        
        int ans = -1;
        
        while (!cells.empty())
        {
            const auto cell = cells.front();
            cells.pop();
            
            for (int d = 0; d < 4; d++)
            {
                const auto i = cell.first + di[d];
                const auto j = cell.second + dj[d];
                
                if (i < 0 || i == n || j < 0 || j == m || dist[i][j] != -1)
                {
                    continue;
                }
                
                dist[i][j] = dist[cell.first][cell.second] + 1;
                ans = std::max(ans, dist[i][j]);
                cells.push({i, j});
            }
        }
        
        return ans;
    }
};
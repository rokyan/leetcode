// https://leetcode.com/problems/map-of-highest-peak/

class Solution 
{
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater)
    {
        const auto n = std::size(isWater);
        const auto m = std::size(isWater.front());
        
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
        
        std::queue<std::pair<int, int>> q;
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (isWater[i][j])
                {
                    q.push({ i, j });
                    dist[i][j] = 0;
                }
            }
        }
        
        std::vector<int> di { 1, 0, -1, 0 };
        std::vector<int> dj { 0, -1, 0, 1 };
        
        while (!q.empty())
        {
            auto pos = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++)
            {
                auto i = pos.first + di[k];
                auto j = pos.second + dj[k];
                
                if (i >= 0 && i < n && j >= 0 && j < m && dist[i][j] == -1)
                {
                    dist[i][j] = dist[pos.first][pos.second] + 1;
                    q.push({ i, j });
                }
            }
        }
        
        return dist;
    }
};
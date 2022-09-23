// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution
{
private:
    static constexpr int INF = 1000 * 1000 * 1000;
    
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold)
    {
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
        
        for (const auto& edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            const int d = edge[2];
            
            dist[u][v] = dist[v][u] = d;
        }
        
        for (int u = 0; u < n; u++)
        {
            dist[u][u] = 0;
        }
        
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int ans = 0;
        int cnt_ans = INF;
        
        for (int u = 0; u < n; u++)
        {
            int cnt = 0;
            
            for (int v = 0; v < n; v++)
            {
                if (dist[u][v] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            
            if (cnt <= cnt_ans)
            {
                cnt_ans = cnt;
                ans = u;
            }
        }
        
        return ans;
    }
};
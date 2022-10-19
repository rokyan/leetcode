// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/

class Solution
{
private:
    static constexpr int INF = 1000000;
    
public:
    std::vector<int> countSubgraphsForEachDiameter(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
        
        for (const auto& e : edges)
        {
            const auto u = e[0] - 1;
            const auto v = e[1] - 1;
            
            dist[u][v] = dist[v][u] = 1;
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
        
        std::vector<int> answer(n - 1);
        
        for (int mask = 0; mask < (1 << n); mask++)
        {
            auto max_dist = 0;
            auto nodes_count = 0;
            auto edges_count = 0;
            
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    nodes_count++;
                    
                    for (int j = i + 1; j < n; j++)
                    {
                        if (mask & (1 << j))
                        {
                            max_dist = std::max(max_dist, dist[i][j]);
                            
                            if (dist[i][j] == 1)
                            {
                                edges_count++;
                            }
                        }
                    }
                }
            }
            
            if (nodes_count > 1 && nodes_count == edges_count + 1)
            {
                answer[max_dist - 1]++;
            }
        }
        
        return answer;
    }
};
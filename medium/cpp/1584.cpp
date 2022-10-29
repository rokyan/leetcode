// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution
{
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points)
    {
        const auto n = std::size(points);
        
        std::vector<char> used(n);
        std::vector<int> distance(n, std::numeric_limits<int>::max());
        
        distance[0] = 0;
        
        int sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            int v = -1;
            
            for (int u = 0; u < n; u++)
            {
                if (!used[u] && (v == -1 || distance[u] < distance[v]))
                {
                    v = u;
                }
            }
            
            sum += distance[v];
            used[v] = true;
            
            for (int u = 0; u < n; u++)
            {
                if (!used[u])
                {
                    const auto n_distance = std::abs(points[v][0] - points[u][0]) + std::abs(points[v][1] - points[u][1]);
                    
                    if (n_distance < distance[u])
                    {
                        distance[u] = n_distance;
                    }
                }
            }
        }
        
        return sum;
    }
};
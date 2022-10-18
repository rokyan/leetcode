// https://leetcode.com/problems/network-delay-time/

class Solution
{
private:
    static constexpr int INF = 1000 * 1000 + 1;
    
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        
        for (const auto& edge : times)
        {
            const auto from = edge[0] - 1;
            const auto to = edge[1] - 1;
            const auto dist = edge[2];
            
            graph[from].emplace_back(to, dist);
        }
        
        std::vector<int> dist(n, INF);
        dist[k - 1] = 0;
        
        std::set<std::pair<int, int>> q;
        q.insert({ 0, k - 1 });
        
        while (!q.empty())
        {
            const auto v = std::begin(q)->second;
            
            q.erase(std::begin(q));
            
            for (const auto& edge : graph[v])
            {
                const auto to = edge.first;
                const auto to_dist = edge.second;
                
                if (dist[to] > dist[v] + to_dist)
                {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + to_dist;
                    q.insert({ dist[to], to });
                }
            }
        }
        
        auto max_dist =  *std::max_element(std::begin(dist), std::end(dist));
        
        return max_dist == INF ? -1 : max_dist;
    }
};
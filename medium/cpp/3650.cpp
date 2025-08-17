// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/

class Solution
{
public:
    int minCost(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            const auto u = edge[0];
            const auto v = edge[1];
            const auto w = edge[2];

            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, 2 * w);
        }

        std::vector<int> dist(n, -1);
        dist[0] = 0;

        std::set<std::pair<int, int>> q;
        q.emplace(0, 0);

        while (!q.empty())
        {
            const auto [v, d] = *std::cbegin(q);
            q.erase(std::cbegin(q));

            for (const auto [to, w] : graph[v])
            {
                if (dist[to] == -1 || dist[to] > dist[v] + w)
                {
                    if (const auto it = q.find({dist[to], to}); it != std::cend(q))
                    {
                        q.erase({dist[to], to});
                    }
                    dist[to] = dist[v] + w;
                    q.emplace(to, dist[to]);
                }
            }
        }

        return dist.back();
    }
};
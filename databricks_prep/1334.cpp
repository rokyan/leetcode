class Solution
{
private:
    static constexpr int inf = 1000'000'000;

public:
    int findTheCity(int n,const std::vector<std::vector<int>>& edges, int distanceThreshold)
    {
        const auto graph = buildGraph(n, edges);

        int city = -1;
        int reachable = -1;

        for (int v = 0; v < n; v++)
        {
            std::vector<int> distance(n, inf);
            distance[v] = 0;

            std::set<std::pair<int, int>> q;
            q.insert({0, v});

            while (!q.empty())
            {
                const auto [d, u] = *std::cbegin(q);
                q.erase(std::cbegin(q));

                for (auto [to, w] : graph[u])
                {
                    if (distance[to] > distance[u] + w)
                    {
                        q.erase({distance[to], to});
                        distance[to] = distance[u] + w;
                        q.insert({distance[to], to});
                    }
                }
            }

            int counter = 0;

            for (int u = 0; u < n; u++)
            {
                if (u != v && distance[u] <= distanceThreshold)
                {
                    counter++;
                }
            }

            if (reachable == -1 || counter <= reachable)
            {
                reachable = counter;
                city = v;
            }
        }

        return city;
    }

private:
    std::vector<std::vector<std::pair<int, int>>> buildGraph(
        int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        return graph;
    }
};
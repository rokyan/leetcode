// https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000 + 7;

public:
    int minTime(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<std::vector<int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2], edge[3]});
        }

        std::vector<int> dist(n, inf);
        dist[0] = 0;

        std::set<std::pair<int, int>> q;
        q.insert({0, 0});

        while (!q.empty())
        {
            const auto [d, v] = *std::cbegin(q);
            q.erase(std::cbegin(q));

            for (const auto& edge : graph[v])
            {
                const auto to = edge[0];
                const auto start = edge[1];
                const auto end = edge[2];

                if (dist[v] <= end)
                {
                    const auto time = std::max(dist[v], start) + 1;

                    if (dist[to] > time)
                    {
                        q.erase({dist[to], to});
                        dist[to] = time;
                        q.insert({dist[to], to});
                    }
                }
            }
        }

        return dist[n - 1] == inf ? -1 : dist[n - 1];
    }
};
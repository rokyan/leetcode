// https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000 + 7;

public:
    std::vector<int> minimumTime(int n,
        const std::vector<std::vector<int>>& edges, const std::vector<int>& disappear)
    {
        auto graph = build(n, edges);

        std::priority_queue<std::pair<int, int>> pq;
        pq.push({ 0, 0 });

        std::vector<int> dist(n, inf);
        dist[0] = 0;

        while (!pq.empty())
        {
            const auto [d, v] = pq.top();
            pq.pop();

            if (-d > dist[v])
            {
                continue;
            }

            for (const auto [to, w] : graph[v])
            {
                if (-d + w < dist[to] && -d + w < disappear[to])
                {
                    dist[to] = -d + w;
                    pq.push({ -dist[to], to });
                }
            }
        }

        for (auto& d : dist)
        {
            if (d == inf)
            {
                d = -1;
            }
        }

        return dist;
    }

private:
    std::vector<vector<std::pair<int, int>>> build(int n, const std::vector<std::vector<int>>& edges)
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
// https://leetcode.com/problems/minimum-cost-to-repair-edges-to-traverse-a-graph/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<std::pair<int, int>>>;

public:
    int minCost(int n, const std::vector<std::vector<int>>& edges, int k)
    {
        const auto graph{build_graph(n, edges)};

        const int upper_bound = (*std::max_element(edges.cbegin(), edges.cend(),
            [](const auto& lhs, const auto& rhs) {
                return lhs[2] < rhs[2];
            }))[2] + 1;

        int lo = 0;
        int hi = upper_bound;

        while (lo < hi)
        {
            const int mid = lo + (hi - lo) / 2;

            if (solve(n, k, graph, mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo == upper_bound ? -1 : lo;
    }

private:
    graph_type build_graph(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        return graph;
    }

    bool solve(int n, int k, const graph_type& graph, int money)
    {
        std::vector<int> dist(n, -1);
        dist[0] = 0;

        std::queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            const int v = q.front();
            q.pop();

            if (dist[v] > k)
            {
                continue;
            }

            for (const auto& [to, w] : graph[v])
            {
                if (w <= money && dist[to] == -1)
                {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist[n - 1] != -1 && dist[n - 1] <= k;
    }
};
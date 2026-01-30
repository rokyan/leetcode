// https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    int specialNodes(int n, const std::vector<std::vector<int>>& edges, int x, int y, int z)
    {
        graph_type graph{build(n, edges)};

        std::vector<int> xdist(n, -1), ydist(n, -1), zdist(n, -1);
        dfs(x, graph, xdist);
        dfs(y, graph, ydist);
        dfs(z, graph, zdist);

        int res = 0;

        for (int u = 0; u < n; u++)
        {
            std::vector<int> allDist{xdist[u], ydist[u], zdist[u]};
            std::ranges::sort(allDist);
            res += 1LL * allDist[2] * allDist[2] == 1LL * allDist[0] * allDist[0] + 1LL * allDist[1] * allDist[1];
        }

        return res;
    }

private:
    graph_type build(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph(n);

        for (const auto& edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return graph;
    }

    void dfs(int v, const graph_type& graph,
        std::vector<int>& dist, int curDist = 0)
    {
        dist[v] = curDist;

        for (const int to : graph[v])
        {
            if (dist[to] == -1)
            {
                dist[to] = dist[v] + 1;
                dfs(to, graph, dist, curDist + 1);
            }
        }
    }
};
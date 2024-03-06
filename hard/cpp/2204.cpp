// https://leetcode.com/problems/distance-to-a-cycle-in-undirected-graph/description/

class Solution
{
public:
    std::vector<int> distanceToCycle(int n, std::vector<std::vector<int>>& edges)
    {
        const auto graph = build(n, edges);

        std::vector<char> color(n);
        std::vector<int> prev(n, -1);

        auto start = 0;
        auto end = 0;

        dfs(0, -1, graph, color, prev, start, end);

        std::vector<int> dist(n, -1);
        std::queue<int> q;

        while (end != start)
        {
            dist[start] = 0;
            q.push(start);
            start = prev[start];
        }

        dist[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();

            for (auto to : graph[v])
            {
                if (dist[to] == -1)
                {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }

private:
    std::vector<std::vector<int>> build(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    bool dfs(int v, int p, const std::vector<std::vector<int>>& graph,
        std::vector<char>& color, std::vector<int>& prev, int& start, int& end)
    {
        color[v] = 1;

        for (auto to : graph[v])
        {
            if (color[to] == 0)
            {
                prev[to] = v;

                if (dfs(to, v, graph, color, prev, start, end))
                {
                    return true;
                }
            }
            else if (color[to] == 1 && to != p)
            {
                start = v;
                end = to;
                return true;
            }
        }

        color[v] = 2;

        return false;
    }
};
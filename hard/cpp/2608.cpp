// https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

class Solution
{
public:
    int findShortestCycle(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n, std::vector<int>());

        for (const auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        auto res = -1;

        for (auto v = 0; v < n; v++)
        {
            bfs(v, n, graph, res);
        }

        return res;
    }

private:
    void bfs(int v, int n, std::vector<std::vector<int>>& graph, int& res)
    {
        std::vector<int> dist(n, -1);
        std::vector<int> parent(n, -1);

        std::queue<int> q;
        q.push(v);

        dist[v] = 0;

        while (!q.empty())
        {
            const auto u = q.front();
            q.pop();

            for (auto to : graph[u])
            {
                if (dist[to] == -1)
                {
                    dist[to] = dist[u] + 1;
                    parent[to] = u;
                    q.push(to);
                }
                else if (to != parent[u])
                {
                    const auto upd = dist[to] + dist[u] + 1;

                    res = res == -1 ? upd : std::min(upd, res);
                }
            }
        }
    }
};
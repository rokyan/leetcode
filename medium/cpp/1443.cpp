// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

class Solution
{
public:
    int minTime(int n, const std::vector<std::vector<int>>& edges, const std::vector<bool>& hasApple)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<int> parent(n, -1);
        dfs(0, -1, graph, parent);

        std::queue<int> q;
        std::vector<bool> visited(n);

        auto res = 0;

        for (auto v = 0; v < n; v++)
        {
            if (hasApple[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();

            if (v != 0)
            {
                res += 2;

                if (!visited[parent[v]])
                {
                    visited[parent[v]] = true;
                    q.push(parent[v]);
                }
            }
        }

        return res;
    }

private:
    void dfs(int v, int p, const std::vector<std::vector<int>>& graph, std::vector<int>& parent)
    {
        parent[v] = p;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, graph, parent);
            }
        }
    }
};
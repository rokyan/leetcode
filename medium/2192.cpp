// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

class Solution
{
public:
    std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<std::vector<int>> res(n);
        std::vector<bool> visited(n);

        for (auto v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                dfs(v, visited, res, graph);
            }
        }

        return res;
    }

private:
    void dfs(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& res, std::vector<std::vector<int>>& graph)
    {
        visited[v] = true;

        for (auto to : graph[v])
        {
            if (!visited[to])
            {
                dfs(to, visited, res, graph);
            }

            res[v].push_back(to);
            res[v].insert(std::end(res[v]), std::begin(res[to]), std::end(res[to]));
        }

        std::sort(std::begin(res[v]), std::end(res[v]));
        
        const auto end = std::unique(std::begin(res[v]), std::end(res[v]));
        res[v].erase(end, std::end(res[v]));
    }
};
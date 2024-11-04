// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution
{
public:
    std::vector<int> eventualSafeNodes(const std::vector<std::vector<int>>& graph)
    {
        const auto n = std::size(graph);

        visited.resize(n);
        safe.resize(n);

        for (auto v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                dfs(v, graph);
            }
        }

        std::vector<int> res;
        res.reserve(n);

        for (auto v = 0; v < n; v++)
        {
            if (safe[v])
            {
                res.push_back(v);
            }
        }

        return res;
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph)
    {
        visited[v] = true;
        auto res = true;

        for (auto to : graph[v])
        {
            if (!visited[to])
            {
                dfs(to, graph);
            }

            res &= safe[to];
        }

        safe[v] = res;
    }

private:
    std::vector<bool> visited;
    std::vector<bool> safe;
};
// https://leetcode.com/problems/remove-methods-from-project/description/

class Solution
{
public:
    std::vector<int> remainingMethods(int n, int k, const std::vector<std::vector<int>>& invocations)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& invocation : invocations)
        {
            graph[invocation[0]].push_back(invocation[1]);
        }

        std::vector<char> visited(n);
        dfs(k, graph, visited);

        auto can_be_removed = true;

        for (auto v = 0; v < n && can_be_removed; v++)
        {
            if (visited[v])
            {
                continue;
            }

            for (auto to : graph[v])
            {
                if (visited[to])
                {
                    can_be_removed = false;
                    break;
                }
            }
        }

        std::vector<int> res;
        res.reserve(n);

        for (auto v = 0; v < n; v++)
        {
            if (!visited[v] || !can_be_removed)
            {
                res.push_back(v);
            }
        }

        return res;
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<char>& visited)
    {
        visited[v] = true;

        for (auto to : graph[v])
        {
            if (!visited[to]) dfs(to, graph, visited);
        }
    }
};
// https://leetcode.com/problems/find-champion-ii/description/

class Solution
{
public:
    int findChampion(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        std::vector<char> visited(n);

        std::vector<int> order;
        order.reserve(n);

        for (auto v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                dfs(v, graph, visited, order);
            }
        }

        std::ranges::reverse(order);

        auto winner = order.front();

        std::ranges::fill(visited, false);

        if (dfs2(winner, graph, visited) == n)
        {
            return winner;
        }

        return -1;
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<char>& visited, std::vector<int>& order)
    {
        visited[v] = true;

        for (auto to : graph[v])
        {
            if (!visited[to]) dfs(to, graph, visited, order);
        }

        order.push_back(v);
    }

    int dfs2(int v, const std::vector<std::vector<int>>& graph, std::vector<char>& visited)
    {
        auto cnt = 1;
        visited[v] = true;

        for (auto to : graph[v])
        {
            if (!visited[to]) cnt += dfs2(to, graph, visited);
        }

        return cnt;
    }
};
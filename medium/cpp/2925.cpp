// https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/description/

class Solution
{
public:
    long long maximumScoreAfterOperations(std::vector<std::vector<int>>& edges, std::vector<int>& values)
    {
        const auto graph = build(edges);

        const auto n = std::size(graph);

        std::vector<long long> dp(n);
        static_cast<void>(dfs(0, -1, graph, values, dp));

        return dp.front();
    }

private:
    std::vector<std::vector<int>> build(const std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    long long dfs(int v, int p, const std::vector<std::vector<int>>& graph,
        const std::vector<int>& values, std::vector<long long>& dp)
    {
        if (std::size(graph[v]) == 1 && p != -1)
        {
            return values[v];
        }

        auto s = 0LL;
        dp[v] = values[v];

        for (auto to : graph[v])
        {
            if (to != p)
            {
                s += dfs(to, v, graph, values, dp);
                dp[v] += dp[to];
            }
        }

        dp[v] = std::max(dp[v], s);

        return s + values[v];
    }
};
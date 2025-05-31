// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int assignEdgeWeights(const std::vector<std::vector<int>>& edges)
    {
        const auto graph = build(edges);
        const auto len = dfs(0, -1, graph);

        return pow(len - 2);
    }

private:
    std::vector<std::vector<int>> build(const std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        return graph;
    }

    int dfs(int v, int prev, const std::vector<std::vector<int>>& graph)
    {
        auto len = 0;

        for (auto to : graph[v])
        {
            if (to != prev)
            {
                len = std::max(len, dfs(to, v, graph));
            }
        }

        return 1 + len;
    }

    int pow(int p)
    {
        if (p == 0)
        {
            return 1;
        }

        if (p % 2 == 1)
        {
            return 1LL * 2 * pow(p - 1) % mod;
        }

        const auto inter = pow(p / 2);
        return 1LL * inter * inter % mod;
    }
};
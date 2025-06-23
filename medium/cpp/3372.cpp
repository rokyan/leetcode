// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/

class Solution
{
public:
    std::vector<int> maxTargetNodes(
        const std::vector<std::vector<int>>& edges1,
        const std::vector<std::vector<int>>& edges2,
        int k)
    {
        const auto graph1 = build(edges1);
        const auto graph2 = build(edges2);

        std::vector<int> k1(std::size(graph1));

        for (auto v = 0; v < std::size(graph1); v++)
        {
            k1[v] = dfs(v, -1, k, graph1);
        }

        auto maxVal = 0;

        if (k > 0)
        {
            for (auto v = 0; v < std::size(graph2); v++)
            {
                maxVal = std::max(maxVal, dfs(v, -1, k - 1, graph2));
            }
        }

        std::vector<int> res(std::size(graph1));

        for (auto v = 0; v < std::size(graph1); v++)
        {
            res[v] = k1[v] + maxVal;
        }

        return res;
    }

private:
    std::vector<std::vector<int>> build(const std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges);

        std::vector<std::vector<int>> graph(n + 1);

        for (const auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    int dfs(int v,int p, int d, const std::vector<std::vector<int>>& graph)
    {
        if (d == 0)
        {
            return 1;
        }

        auto s = 0;

        for (const auto to : graph[v])
        {
            if (to != p)
            {
                s += dfs(to, v, d - 1, graph);
            }
        }

        return 1 + s;
    }
};
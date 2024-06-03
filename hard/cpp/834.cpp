// https://leetcode.com/problems/sum-of-distances-in-tree/description/

class Solution
{
public:
    std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        std::vector<int> size(n);
        std::vector<int> dst(n);

        dfs1(0, -1, graph, size, dst);

        std::vector<int> res(n);
        res[0] = dst[0];

        dfs2(0, -1, n, graph, size, dst, res);

        return res;
    }

private:
    void dfs1(int v, int p, const std::vector<std::vector<int>>& graph,
        std::vector<int>& size, std::vector<int>& dst)
    {
        size[v] = 1;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs1(to, v, graph, size, dst);
                size[v] += size[to];
                dst[v] += dst[to] + size[to];
            }
        }
    }

    void dfs2(int v, int p, int n, const std::vector<std::vector<int>>& graph,
        const std::vector<int>& size, const std::vector<int>& dst, std::vector<int>& res)
    {
        for (auto to : graph[v])
        {
            if (to != p)
            {
                const auto rem = res[v] - dst[to] - size[to];
                res[to] = dst[to] + rem + n - size[to];
                dfs2(to, v, n, graph, size, dst, res);
            }
        }
    }
};
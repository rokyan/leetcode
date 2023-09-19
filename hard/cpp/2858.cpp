// https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/description/

class Solution
{
public:
    std::vector<int> minEdgeReversals(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], 0);
            graph[edge[1]].emplace_back(edge[0], 1);
        }

        std::vector<int> ans(n);

        ans[0] = dfs1(0, graph);

        static_cast<void>(dfs2(0, graph, ans));

        return ans;
    }

private:
    int dfs1(int root, const std::vector<std::vector<std::pair<int, int>>>& graph, int parent = -1)
    {
        auto tot = 0;

        for (auto entry : graph[root])
        {
            if (entry.first != parent)
            {
                tot += entry.second + dfs1(entry.first, graph, root);
            }
        }

        return tot;
    }

    int dfs2(int root, const std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<int>& ans, int parent = -1, int dir = 0, int rev = 0)
    {
        auto tot = 0;

        for (auto entry : graph[root])
        {
            if (entry.first != parent)
            {
                tot += entry.second + dfs2(entry.first, graph, ans, root, dir + (entry.second == 0), rev + (entry.second == 1));
            }
        }

        ans[root] = tot + (ans[0] - tot - rev + dir);

        return tot;
    }
};
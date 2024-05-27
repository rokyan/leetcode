// https://leetcode.com/problems/maximum-subtree-of-the-same-color/description/

class Solution
{
public:
    int maximumSubtreeSize(std::vector<std::vector<int>>& edges, std::vector<int>& colors)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        auto res = 0;

        static_cast<void>(dfs(0, graph, colors, res));

        return res;
    }

private:
    std::pair<bool, int> dfs(int v, const std::vector<std::vector<int>>& graph, const std::vector<int>& colors, int& res)
    {
        auto same = true;
        auto size = 1;

        for (auto to : graph[v])
        {
            auto [same_in_subtree, subtree_size] = dfs(to, graph, colors, res);

            if (!same_in_subtree)
            {
                same = false;
            }

            if (colors[to] != colors[v])
            {
                same = false;
            }

            size += subtree_size;
        }

        if (same)
        {
            res = std::max(res, size);
        }

        return { same, size };
    }
};
// https://leetcode.com/problems/choose-edges-to-maximize-score-in-a-tree/description/

class Solution
{
public:
    long long maxScore(std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges);

        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (auto v = 1; v < n; v++)
        {
            graph[edges[v][0]].push_back({ v, edges[v][1] });
        }

        const auto res = dfs(0, graph);

        return std::max(res.first, res.second);
    }

private:
    std::pair<long long, long long> dfs(int v, const std::vector<std::vector<std::pair<int, int>>>& graph)
    {
        auto res = std::make_pair(0LL, 0LL);
        auto acc = 0LL;
        std::vector<std::pair<long long, long long>> c;
        c.reserve(std::size(graph[v]));

        for (auto [to, w] : graph[v])
        {
            const auto cur = dfs(to, graph);
            res.second += std::max(cur.first, cur.second);
            acc += std::max(cur.first, cur.second);
            c.push_back(cur);
        }

        for (auto i = 0; i < std::size(graph[v]); i++)
        {
            const auto w = graph[v][i].second;
            res.first = std::max(res.first, acc - std::max(c[i].first, c[i].second) + c[i].second + w);
        }

        return res;
    }
};
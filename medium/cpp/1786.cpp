// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/

class Solution
{
private:
    static constexpr auto inf = 2000'000'000 + 1;
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countRestrictedPaths(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0] - 1].emplace_back(edge[1] - 1, edge[2]);
            graph[edge[1] - 1].emplace_back(edge[0] - 1, edge[2]);
        }

        std::vector<int> dst(n, inf);
        dst[n - 1] = 0;

        std::priority_queue<std::pair<int, int>> heap;
        heap.push({ 0, n - 1 });

        while (!heap.empty())
        {
            const auto [_, v] = heap.top();
            heap.pop();

            for (const auto [to, w] : graph[v])
            {
                if (dst[to] > dst[v] + w)
                {
                    dst[to] = dst[v] + w;
                    heap.push({ -dst[to], to });
                }
            }
        }

        std::unordered_map<int, int> memo;

        dfs(n - 1, graph, memo, dst);

        return memo[n - 1];
    }

private:
    void dfs(int v, const std::vector<std::vector<std::pair<int, int>>>& graph,
        std::unordered_map<int, int>& memo, const std::vector<int>& dst)
    {
        memo[v] = v == 0;

        for (const auto [to, _] : graph[v])
        {
            if (dst[to] > dst[v])
            {
                if (memo.find(to) == std::end(memo))
                {
                    dfs(to, graph, memo, dst);
                }

                memo[v] += memo[to];
                memo[v] %= mod;
            }
        }
    }
};
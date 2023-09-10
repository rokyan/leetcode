// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

class Solution
{
public:
    long long minimumFuelCost(std::vector<std::vector<int>>& roads, int seats)
    {
        const auto n = std::size(roads) + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& road : roads)
        {
            const auto u = road[0];
            const auto v = road[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        std::vector<int> cnt(n);

        dfs(0, -1, graph, cnt);

        auto res = 0LL;

        for (auto v = 1; v < n; v++)
        {
            res += (cnt[v] + seats - 1) / seats;
        }

        return res;
    }

private:
    void dfs(int v, int p, std::vector<std::vector<int>>& graph, std::vector<int>& cnt)
    {
        cnt[v] = 1;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, graph, cnt);
                cnt[v] += cnt[to];
            }
        }
    }
};
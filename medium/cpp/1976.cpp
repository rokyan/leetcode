// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution
{
private:
    static constexpr auto inf = 1e18;
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countPaths(int n, const std::vector<std::vector<int>>& roads)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& road : roads)
        {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }

        std::vector<long long> dst(n, inf);
        dst[0] = 0;

        std::priority_queue<std::pair<long long, int>,
            std::vector<std::pair<long long, int>>,
            std::greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty())
        {
            const auto [d, v] = pq.top();
            pq.pop();

            if (d > dst[v])
            {
                continue;
            }

            for (const auto [to, w] : graph[v])
            {
                if (dst[to] > dst[v] + w)
                {
                    dst[to] = dst[v] + w;
                    pq.emplace(dst[to], to);
                }
            }
        }

        std::vector<int> dp(n, -1);
        dp[0] = 1;
        calc(n - 1, dp, dst, graph);

        return dp[n - 1];
    }

private:
    int calc(int v, std::vector<int>& dp, const std::vector<long long>& dst,
        const std::vector<std::vector<std::pair<int, int>>>& graph)
    {
        if (dp[v] != -1)
        {
            return dp[v];
        }

        dp[v] = 0;

        for (auto [to, w] : graph[v])
        {
            if (dst[to] + w == dst[v])
            {
                dp[v] += calc(to, dp, dst, graph);
                dp[v] %= mod;
            }
        }

        return dp[v];
    }
};
// https://leetcode.com/problems/minimum-cost-to-buy-apples/

class Solution
{
private:
    using graph_type = std::vector<std::vector<std::pair<int, int>>>;

public:
    std::vector<long long> minCost(int n, std::vector<std::vector<int>>& roads, std::vector<int>& appleCost, int k)
    {
        const auto graph = transform(n, roads);

        std::vector<long long> res(n);

        for (auto v = 0; v < n; v++)
        {
            res[v] = meow(n, graph, v, appleCost, k);
        }

        return res;
    }

private:
    graph_type transform(int n, const std::vector<std::vector<int>>& roads)
    {
        graph_type graph(n);

        for (auto&& road : roads)
        {
            graph[road[0] - 1].emplace_back(road[1] - 1, road[2]);
            graph[road[1] - 1].emplace_back(road[0] - 1, road[2]);
        }

        return graph;
    }

    long long meow(int n, const graph_type& graph, int start, const std::vector<int>& cost, int k)
    {
        std::vector<long long> dst(n, 1000'000'000'000L);
        dst[start] = 0;

        std::priority_queue<std::pair<int, int>> q;
        q.push({ 0, start });

        while (!q.empty())
        {
            const auto [d, v] = q.top();
            q.pop();

            for (auto [to, c] : graph[v])
            {
                if (dst[to] > c + d)
                {
                    dst[to] = c + d;
                    q.push({ dst[to], to });
                }
            }
        }

        for (auto v = 0; v < n; v++)
        {
            dst[v] += k * dst[v] + cost[v];
        }

        return *std::min_element(std::cbegin(dst), std::cend(dst));
    }
};
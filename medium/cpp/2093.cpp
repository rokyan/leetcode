// https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

    using graph_type = std::vector<std::vector<std::pair<int, int>>>;

public:
    int minimumCost(int n, std::vector<std::vector<int>>& highways, int discounts)
    {
        const auto graph = build(n, highways);
        const auto len = get_len(n, discounts, graph);
        return len == inf ? -1 : len;
    }

private:
    graph_type build(int n, const std::vector<std::vector<int>>& highways)
    {
        graph_type graph(n);

        for (const auto& highway : highways)
        {
            graph[highway[0]].emplace_back(highway[1], highway[2]);
            graph[highway[1]].emplace_back(highway[0], highway[2]);
        }

        return graph;
    }

    int get_len(int n, int discounts, const graph_type& graph)
    {
        std::vector<std::vector<int>> dst(n, std::vector<int>(discounts + 1, inf));

        std::priority_queue<std::tuple<int, int, int>> heap;
        heap.push({ 0, 0, 0 });

        dst[0][0] = 0;

        while (!heap.empty())
        {
            const auto [_, v, d] = heap.top();
            heap.pop();

            for (const auto [to, w] : graph[v])
            {
                if (dst[v][d] + w < dst[to][d])
                {
                    dst[to][d] = dst[v][d] + w;
                    heap.push({ -dst[to][d], to, d });
                }

                if (d + 1 <= discounts && dst[v][d] + w / 2 < dst[to][d + 1])
                {
                    dst[to][d + 1] = dst[v][d] + w / 2;
                    heap.push({ -dst[to][d + 1], to, d + 1 });
                }
            }
        }

        return *std::min_element(std::cbegin(dst[n - 1]), std::cend(dst[n - 1]));
    }
};
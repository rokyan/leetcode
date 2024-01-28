// https://leetcode.com/problems/find-shortest-path-with-k-hops/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000 + 7;

public:
    int shortestPathWithHops(int n, std::vector<std::vector<int>>& edges, int s, int d, int k)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        std::vector<std::vector<int>> dst(n, std::vector<int>(k + 1, inf));
        dst[s][0] = 0;

        std::priority_queue<std::tuple<int, int, int>> heap;
        heap.push({ 0, s, 0 });

        while (!heap.empty())
        {
            const auto [_, v, hops] = heap.top();
            heap.pop();

            for (const auto [to, w] : graph[v])
            {
                if (dst[to][hops] > dst[v][hops] + w)
                {
                    dst[to][hops] = dst[v][hops] + w;
                    heap.push({ -dst[to][hops], to, hops });
                }

                if (hops < k && dst[to][hops + 1] > dst[v][hops])
                {
                    dst[to][hops + 1] = dst[v][hops];
                    heap.push({ -dst[to][hops + 1], to, hops + 1 });
                }
            }
        }

        return *std::min_element(std::cbegin(dst[d]), std::cend(dst[d]));
    }
};
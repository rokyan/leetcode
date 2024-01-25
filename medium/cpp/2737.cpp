// https://leetcode.com/problems/find-the-closest-marked-node/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int minimumDistance(int n, std::vector<std::vector<int>>& edges, int s, std::vector<int>& marked)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }

        std::vector<int> dst(n, inf);
        dst[s] = 0;

        std::priority_queue<std::pair<int, int>> heap;
        heap.push({ 0, s });

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

        auto res = -1;

        for (const auto v : marked)
        {
            if (dst[v] != inf)
            {
                res = res == -1 ? dst[v] : min(res, dst[v]);
            }
        }

        return res;
    }
};
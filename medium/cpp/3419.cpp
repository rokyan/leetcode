// https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/description/

class Solution
{
public:
    int minMaxWeight(int n, std::vector<std::vector<int>>& edges, int threshold)
    {
        std::sort(std::begin(edges), std::end(edges), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        auto lo = 0;
        auto hi = 0;

        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            const auto from = edge[1];
            const auto to = edge[0];
            hi = std::max(hi, edge[2]);

            graph[from].push_back({to, edge[2]});
        }

        auto res = -1;

        while (lo <= hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            std::vector<char> visited(n);
            visited[0] = true;

            std::queue<int> q;
            q.push(0);

            auto cnt = 0;

            while (!q.empty())
            {
                const auto v = q.front();
                q.pop();

                cnt++;

                for (const auto [to, w] : graph[v])
                {
                    if (!visited[to] && w <= mid)
                    {
                        visited[to] = true;
                        q.push(to);
                    }
                }
            }

            if (cnt == n)
            {
                hi = mid - 1;
                res = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return res;
    }
};
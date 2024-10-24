// https://leetcode.com/problems/find-edges-in-shortest-paths/description/

class Solution
{
private:
    static constexpr auto inf = 10'000'000'000;

public:
    std::vector<bool> findAnswer(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        const auto dst_s = find_shortest(n, 0, graph);
        const auto dst_f = find_shortest(n, n - 1, graph);

        const auto shortest = dst_s[n - 1];

        std::vector<bool> res(std::size(edges));

        for (auto i = 0; i < std::size(edges); i++)
        {
            const auto& edge = edges[i];

            if (dst_s[edge[0]] + edge[2] + dst_f[edge[1]] == shortest)
            {
                res[i] = true;
            }

            if (dst_s[edge[1]] + edge[2] + dst_f[edge[0]] == shortest)
            {
                res[i] = true;
            }
        }

        return res;
    }

private:
    std::vector<long long> find_shortest(int n, int start,
        const std::vector<std::vector<std::pair<int, int>>>& graph)
    {
        std::vector<long long> dst(n, inf);
        dst[start] = 0;

        std::set<std::pair<int, int>> s;
        s.insert({0, start});

        while (!s.empty())
        {
            const auto [d, v] = *std::cbegin(s);
            s.erase(std::cbegin(s));

            for (auto [to, w] : graph[v])
            {
                if (dst[to] > dst[v] + w)
                {
                    s.erase({dst[to], to});
                    dst[to] = dst[v] + w;
                    s.insert({dst[to], to});
                }
            }
        }

        return dst;
    }
};
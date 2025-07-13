// https://leetcode.com/problems/unit-conversion-ii/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;
    static constexpr auto maxDepth = 32;

public:
    std::vector<int> queryConversions(
        const std::vector<std::vector<int>>& conversions,
        const std::vector<std::vector<int>>& queries)
    {
        const auto n = std::size(conversions) + 1;

        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& conv : conversions)
        {
            graph[conv[0]].emplace_back(conv[1], conv[2]);
        }

        std::vector<int> dist(n);
        std::vector<int> depth(n);
        std::vector<std::vector<int>> up(n, std::vector<int>(maxDepth, -1));

        dfs(0, -1, graph, 1, dist, up, 0, depth);

        for (auto i = 1; i < maxDepth; i++)
        {
            for (auto v = 0; v < n; v++)
            {
                if (up[v][i - 1] != -1)
                {
                    up[v][i] = up[up[v][i - 1]][i - 1];
                }
            }
        }

        std::vector<int> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            const auto u = query[0];
            const auto v = query[1];
            const auto node = lca(u, v, depth, up);
            // std::cout << node << std::endl;
            const auto toU = 1LL * dist[u] * inv(dist[node]) % mod;
            const auto toV = 1LL * dist[v] * inv(dist[node]) % mod;
            // std::cout << toU << " " << toV << std::endl;
            res.push_back(1LL * inv(toU) * toV % mod);
        }

        return res;
    }

private:
    void dfs(int v, int p, const std::vector<std::vector<std::pair<int, int>>>& graph,
        int len, std::vector<int>& dist, std::vector<std::vector<int>>& up,
        int d, std::vector<int>& depth)
    {
        dist[v] = len;
        up[v][0] = p;
        depth[v] = d;

        for (const auto [to, w] : graph[v])
        {
            dfs(to, v, graph, 1LL * len * w % mod, dist, up, d + 1, depth);
        }
    }

    int lift(int v, int d, const std::vector<std::vector<int>>& up)
    {
        for (auto i = 0; i < maxDepth; i++)
        {
            if (d & (1 << i))
            {
                v = up[v][i];

                if (v == -1)
                {
                    break;
                }
            }
        }

        return v;
    }

    int lca(int u, int v, const std::vector<int>& depth, const std::vector<std::vector<int>>& up)
    {
        if (depth[u] > depth[v])
        {
            std::swap(u, v);
        }

        v = lift(v, depth[v] - depth[u], up);

        if (u == v)
        {
            return v;
        }

        for (auto i = maxDepth - 1; i >= 0; i--)
        {
            if (up[v][i] != -1 && up[v][i] != up[u][i])
            {
                v = up[v][i];
                u = up[u][i];
            }
        }

        return up[v][0];
    }

    int inv(int x)
    {
        return pow(x, mod - 2);
    }

    int pow(int x, int p)
    {
        if (p == 0)
        {
            return 1;
        }

        if (p % 2 == 1)
        {
            return 1LL * x * pow(x, p - 1) % mod;
        }

        const auto temp = pow(x, p / 2);
        return 1LL * temp * temp % mod;
    }
};
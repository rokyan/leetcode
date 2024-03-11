// https://leetcode.com/problems/optimize-water-distribution-in-a-village/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(int n)
        {
            init(n);
        }

        int find(int v)
        {
            if (v == parent[v])
            {
                return v;
            }

            return (parent[v] = find(parent[v]));
        }

        bool merge(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return false;
            }

            if (size[u] > size[v])
            {
                std::swap(u, v);
            }

            parent[u] = v;
            size[v] += size[u];

            return true;
        }

        bool same(int u, int v)
        {
            return find(u) == find(v);
        }

    private:
        void init(int n)
        {
            parent.resize(n);
            std::iota(std::begin(parent), std::end(parent), 0);

            size.resize(n, 1);
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes)
    {
        for (auto v = 0; v < n; v++)
        {
            pipes.push_back({ v + 1, n + 1, wells[v] });
        }

        Dsu dsu{ n + 1 };

        std::sort(std::begin(pipes), std::end(pipes), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        auto res = 0;

        for (const auto& pipe : pipes)
        {
            if (dsu.merge(pipe[0] - 1, pipe[1] - 1))
            {
                res += pipe[2];
            }
        }

        return res;
    }
};
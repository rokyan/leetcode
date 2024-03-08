// https://leetcode.com/problems/graph-connectivity-with-threshold/description/

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

        void merge(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return;
            }

            if (size[u] > size[v])
            {
                std::swap(u, v);
            }

            parent[u] = v;
            size[v] += size[u];
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

            size.resize(n);
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    std::vector<bool> areConnected(int n, int threshold, std::vector<std::vector<int>>& queries)
    {
        if (threshold < 1)
        {
            return std::vector<bool>(std::size(queries), true);
        }

        auto dsu = Dsu{ n };

        for (auto v = threshold + 1; v <= n; v++)
        {
            for (auto u = 1; u * u <= v; u++)
            {
                if (v % u == 0 && u > threshold)
                {
                    dsu.merge(v - 1, u - 1);
                }

                if (v % u == 0 && v / u > threshold)
                {
                    dsu.merge(v - 1, v / u - 1);
                }
            }
        }

        std::vector<bool> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            res.push_back(dsu.same(query[0] - 1, query[1] - 1));
        }

        return res;
    }
};
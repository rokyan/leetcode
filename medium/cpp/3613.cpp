// https://leetcode.com/problems/minimize-maximum-component-cost/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(std::size_t n)
        {
            size.resize(n);
            parent.resize(n);

            for (auto v = 0; v < n; v++)
            {
                parent[v] = v;
            }
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
                size[u] += size[v];
                parent[v] = u;
            }
            else
            {
                size[v] += size[u];
                parent[u] = v;
            }

            return true;
        }

    private:
        std::vector<int> size;
        std::vector<int> parent;
    };

public:
    int minCost(int n, std::vector<std::vector<int>>& edges, int k)
    {
        if (k == n)
        {
            return 0;
        }

        std::ranges::sort(edges, [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        Dsu dsu(n);

        auto comp = n;
        auto res = 0;

        for (const auto& edge : edges)
        {
            const auto u = dsu.find(edge[0]);
            const auto v = dsu.find(edge[1]);

            if (u != v)
            {
                dsu.merge(edge[0], edge[1]);
                comp--;
                res = std::max(res, edge[2]);
            }

            if (comp == k)
            {
                break;
            }
        }

        return res;
    }
};
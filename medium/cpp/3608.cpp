// https://leetcode.com/problems/minimum-time-for-k-connected-components/description/

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
    int minTime(int n, const std::vector<std::vector<int>>& edges, int k)
    {
        auto lo = 0;
        auto hi = 1000'000'000;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (solve(n, k, mid, edges))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }

private:
    bool solve(std::size_t n, int k, int time, const std::vector<std::vector<int>>& edges)
    {
        Dsu dsu{n};
        auto comp = n;

        for (const auto& edge : edges)
        {
            if (edge[2] > time && dsu.merge(edge[0], edge[1]))
            {
                comp--;
            }
        }

        return comp >= k;
    }
};
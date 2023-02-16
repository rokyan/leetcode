// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

class Solution
{
public:
    long long countPairs(int n, std::vector<std::vector<int>>& edges)
    {
        init(n);

        for (const auto& edge : edges)
        {
            un(edge[0], edge[1]);
        }

        std::unordered_set<int> probe;

        auto res = 0LL;

        for (auto v = 0; v < n; v++)
        {
            auto c = find(v);

            if (const auto it = probe.find(c); it == std::cend(probe))
            {
                res += 1LL * size[c] * (n - size[c]);
                probe.insert(c);
            }
        }

        return res >> 1;
    }

private:
    void init(int n)
    {
        parent.resize(n);
        size.resize(n);

        for (auto v = 0; v < n; v++)
        {
            parent[v] = v;
            size[v] = 1;
        }
    }

    int find(int v)
    {
        if (v != parent[v])
        {
            return v = find(parent[v]);
        }

        return v;
    }

    void un(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u != v)
        {
            if (size[u] > size[v])
            {
                parent[v] = u;
                size[u] += size[v];
            }
            else
            {
                parent[u] = v;
                size[v] += size[u];
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
};
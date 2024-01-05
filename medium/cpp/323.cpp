// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

class Solution
{
public:
    int countComponents(int n, std::vector<std::vector<int>>& edges)
    {
        init(n);

        auto res = n;

        for (const auto& e : edges)
        {
            if (un(e[0], e[1]))
            {
                res--;
            }
        }

        return res;
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
        if (v == parent[v])
        {
            return v;
        }

        return parent[v] = find(parent[v]);
    }

    bool un(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
        {
            return false;
        }

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

        return true;
    }
private:
    std::vector<int> parent;
    std::vector<int> size;
};
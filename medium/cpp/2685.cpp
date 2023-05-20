// https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution
{
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges)
    {
        init(n);

        auto res = n;

        for (const auto& edge : edges)
        {
            const auto u = edge[0];
            const auto v = edge[1];

            if (un(u, v))
            {
                res--;
            }
        }

        std::unordered_map<int, int> cnt;

        for (const auto& edge : edges)
        {
            const auto u = edge[0];

            cnt[find(u)]++;
        }

        for (const auto& entry : cnt)
        {
            if (entry.second != size[entry.first] * (size[entry.first] - 1) / 2)
            {
                res--;
            }
        }

        return res;
    }

private:
    void init(std::size_t n)
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

        return (parent[v] = find(parent[v]));
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
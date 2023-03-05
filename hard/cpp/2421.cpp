// https://leetcode.com/problems/number-of-good-paths/description/

class Solution
{
public:
    int numberOfGoodPaths(std::vector<int>& vals, std::vector<std::vector<int>>& edges)
    {
        const auto n = static_cast<int>(std::size(edges)) + 1;

        std::vector<std::vector<int>> g(n);

        for (const auto& edge : edges)
        {
            const auto u = edge[0];
            const auto v = edge[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        std::vector<std::pair<int, int>> nv(n);

        for (auto v = 0; v < n; v++)
        {
            nv[v] = { vals[v], v };
        }

        std::sort(std::begin(nv), std::end(nv));

        init(n);

        auto res = 0;

        for (auto i = 0; i < n; )
        {
            auto j = i;

            while (j < n && nv[i].first == nv[j].first)
            {
                j++;
            }

            for (auto k = i; k < j; k++)
            {
                const auto v = nv[k].second;

                for (auto to : g[v])
                {
                    if (vals[to] <= nv[k].first)
                    {
                        un(v, to);
                    }
                }
            }

            std::unordered_map<int, int> cnt;

            for (auto k = i; k < j; k++)
            {
                const auto root = find(nv[k].second);
                cnt[root]++;
            }

            for (const auto& entry : cnt)
            {
                res += entry.second * (entry.second + 1) / 2;
            }

            i = j;
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
        if (parent[v] == v)
        {
            return v;
        }

        return (parent[v] = find(parent[v]));
    }

    void un(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
        {
            return;
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
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
};
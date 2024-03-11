// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/

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

            size.resize(n, 1);
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    vector<bool> distanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList,
        std::vector<std::vector<int>>& queries)
    {
        for (auto i = 0; i < std::size(queries); i++)
        {
            queries[i].push_back(i);
        }

        std::sort(std::begin(queries), std::end(queries), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        std::sort(std::begin(edgeList), std::end(edgeList), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        auto dsu = Dsu{ n };

        std::vector<bool> res(std::size(queries));

        auto p = 0;

        for (const auto& query : queries)
        {
            while (p < std::size(edgeList) && edgeList[p][2] < query[2])
            {
                dsu.merge(edgeList[p][0], edgeList[p][1]);
                p++;
            }

            res[query[3]] = dsu.same(query[0], query[1]);
        }

        return res;
    }
};
// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/description/

class DistanceLimitedPathsExist
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
    DistanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList)
        : n{ n }
        , edges{ edgeList }
    {
        std::sort(std::begin(edges), std::end(edges), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        const auto m = static_cast<int>(std::size(edges));

        block_size = static_cast<int>(sqrt(m));

        Dsu dsu{ n };

        pref.push_back(dsu);

        for (auto i = 0; i < m; i++)
        {
            dsu.merge(edges[i][0], edges[i][1]);

            if ((i + 1) % block_size == 0)
            {
                pref.push_back(dsu);
            }
        }

        if (block_size * block_size < m)
        {
            pref.push_back(dsu);
        }
    }
    
    bool query(int p, int q, int limit)
    {
        const auto lookup = [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs;
        };

        const auto pos =
            std::distance(std::cbegin(edges), std::lower_bound(std::cbegin(edges), std::cend(edges), limit, lookup));

        const auto block = pos / block_size;

        auto dsu = pref[block];
        auto start = block_size * block;

        for (auto i = start; i < std::min<int>(start + block_size, std::size(edges)); i++)
        {
            if (edges[i][2] >= limit)
            {
                break;
            }

            dsu.merge(edges[i][0], edges[i][1]);
        }

        return dsu.same(p, q);
    }

private:
    int n;
    int block_size;
    std::vector<std::vector<int>> edges;
    std::vector<Dsu> pref;
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */
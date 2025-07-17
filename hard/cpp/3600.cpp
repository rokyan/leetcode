// https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(int n)
        {
            size.resize(n);
            parent.resize(n);

            for (auto v = 0; v < n; v++)
            {
                size[v] = 1;
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
    int maxStability(int n, const std::vector<std::vector<int>>& edges, int k)
    {
        Dsu dsu{n};

        std::vector<std::vector<int>> edgesToAdd;
        edgesToAdd.reserve(n);

        auto compCnt = n;
        auto res = -1;

        for (const auto& edge : edges)
        {
            if (edge[3])
            {
                res = res == -1 ? edge[2] : std::min(res, edge[2]);

                if (dsu.merge(edge[0], edge[1]))
                {
                    compCnt--;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                std::vector<int> edgeToAdd{edge[2], edge[0], edge[1]};
                edgesToAdd.push_back(std::move(edgeToAdd));
            }
        }

        std::ranges::sort(edgesToAdd, std::greater<>{});

        std::vector<int> updates;
        updates.reserve(n);

        for (const auto& edge : edgesToAdd)
        {
            if (compCnt > 1 && dsu.merge(edge[1], edge[2]))
            {
                updates.push_back(edge[0]);
                compCnt--;
            }
        }

        if (compCnt > 1)
        {
            return -1;
        }

        std::ranges::sort(updates);

        for (auto i = 0; i < std::size(updates); i++)
        {
            updates[i] *= k > 0 ? 2 : 1;
            k--;
            res = res == -1 ? updates[i] : std::min(res, updates[i]);
        }

        return res;
    }
};
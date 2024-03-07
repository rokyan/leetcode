// https://leetcode.com/problems/process-restricted-friend-requests/description/

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
    std::vector<bool> friendRequests(int n, std::vector<std::vector<int>>& restrictions,
        std::vector<std::vector<int>>& requests)
    {
        std::vector<bool> res(std::size(requests));

        auto dsu = Dsu{ n };

        for (auto q = 0; q < std::size(requests); q++)
        {
            const auto u = requests[q][0];
            const auto v = requests[q][1];

            const auto pu = dsu.find(u);
            const auto pv = dsu.find(v);

            res[q] = true;

            for (const auto& r : restrictions)
            {
                const auto pru = dsu.find(r[0]);
                const auto prv = dsu.find(r[1]);

                if (pu == pru && pv == prv || pu == prv && pv == pru)
                {
                    res[q] = false;
                    break;
                }
            }

            if (res[q])
            {
                dsu.merge(u, v);
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

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
                std::swap(u, v);
            }

            parent[u] = v;
            size[v] += size[u];

            return true;
        }

        int total()
        {
            std::unordered_set<int> un;

            for (auto v : parent)
            {
                un.insert(find(v));
            }

            return std::size(un);
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
    int removeStones(std::vector<std::vector<int>>& stones)
    {
        auto m = stones.front()[1] + 1;

        for (const auto& e : stones)
        {
            m = std::max(m, e[1] + 1);
        }

        std::map<int, int> order;

        for (const auto& e : stones)
        {
            order[e[0] * m + e[1]] = 0;
        }

        auto counter = 0;

        for (auto& e : order)
        {
            e.second = counter++;
        }

        Dsu dsu{ static_cast<int>(std::size(stones)) };

        const auto n = std::size(stones);

        for (auto i = 0; i + 1 < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    const auto from = order[stones[i][0] * m + stones[i][1]];
                    const auto to = order[stones[j][0] * m + stones[j][1]];

                    dsu.un(from, to);
                }
            }
        }

        return std::size(stones) - dsu.total();
    }
};
// https://leetcode.com/problems/connecting-cities-with-minimum-cost/

class Solution
{
private:
    class dsu
    {
    public:
        dsu(int n)
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

            return (v = find(parent[v]));
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
        std::vector<int> size;
        std::vector<int> parent;
    };

public:
    int minimumCost(int n, std::vector<std::vector<int>>& connections)
    {
        dsu d{ n };

        std::sort(std::begin(connections), std::end(connections), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        auto cnt = 0;
        auto tot = 0;

        for (const auto& c : connections)
        {
            if (d.un(c[0] - 1, c[1] - 1))
            {
                cnt++;
                tot += c[2];
            }

            if (cnt == n - 1)
            {
                break;
            }
        }

        return (cnt == n - 1) ? tot : -1;
    }
};
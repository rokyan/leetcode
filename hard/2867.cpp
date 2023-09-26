// https://leetcode.com/problems/count-valid-paths-in-a-tree/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(std::size_t n)
            : size(n)
            , parent(n)
        {
            for (auto v = 0; v < n; v++)
            {
                size[v] = 1;
                parent[v] = v;
            }
        }

        int find(int v)
        {
            if (parent[v] == v)
            {
                return v;
            }

            return (v = find(parent[v]));
        }

        int getSize(int v)
        {
            return size[find(v)];
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
        std::vector<int> size;
        std::vector<int> parent;
    };

public:
    long long countPaths(int n, std::vector<std::vector<int>>& edges)
    {
        Dsu dsu(n);

        std::vector<std::vector<int>> g(n);

        for (const auto& e : edges)
        {
            const auto u = e[0];
            const auto v = e[1];

            if (!isPrime(u) && !isPrime(v))
            {
                dsu.un(u - 1, v - 1);
            }
            else
            {
                if (isPrime(u) && !isPrime(v))
                {
                    g[u - 1].push_back(v - 1);
                }

                if (isPrime(v) && !isPrime(u))
                {
                    g[v - 1].push_back(u - 1);
                }
            }
        }

        auto res = 0LL;

        for (auto v = 0; v < n; v++)
        {
            if (!g[v].empty())
            {
                auto tot = 0;

                for (auto u : g[v])
                {
                    tot += dsu.getSize(u);
                }

                res += tot;

                auto add = 0LL;

                for (auto u : g[v])
                {
                    const auto c = dsu.getSize(u);
                    add += 1LL * c * (tot - c);
                }

                res += add / 2;
            }
        }

        return res;
    }

private:
    bool isPrime(int n)
    {
        if (n < 2)
        {
            return false;
        }

        for (auto i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }
};
class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(std::size_t n)
        {
            parent.resize(n);
            size.resize(n);

            for (auto i = 0; i < n; i++)
            {
                parent[i] = i;
                size[i] = 1;
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
                parent[v] = u;
                size[u] += size[v];
            }
            else
            {
                parent[u] = v;
                size[v] += size[u];
            }
        }

        int get_size(int v)
        {
            return size[find(v)];
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    int largestIsland(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        Dsu dsu(n * m);

        std::array<int, 4> di{0, -1, 0, 1};
        std::array<int, 4> dj{-1, 0, 1, 0};

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (auto d = 0; d < 4; d++)
                    {
                        const auto ni = i + di[d];
                        const auto nj = j + dj[d];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj])
                        {
                            dsu.un(i * m + j, ni * m + nj);
                        }
                    }
                }
            }
        }

        if (dsu.get_size(0) == n * m)
        {
            return n * m;
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (!grid[i][j])
                {
                    std::unordered_set<int> un;

                    for (auto d = 0; d < 4; d++)
                    {
                        const auto ni = i + di[d];
                        const auto nj = j + dj[d];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj])
                        {
                            un.insert(dsu.find(ni * m + nj));
                        }
                    }

                    auto upd = 1;

                    for (auto v : un)
                    {
                        upd += dsu.get_size(v);
                    }

                    res = std::max(res, upd);
                }
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/

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

        void un(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u != v)
            {
                if (size[u] > size[v])
                {
                    std::swap(u, v);
                }

                parent[u] = v;
                size[v] += size[u];
            }
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
    bool hasValidPath(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::set<std::pair<int, int>> vpr
        {
            { 1, 1 }, { 1, 3 }, { 1, 5 },
            { 4, 1 }, { 4, 3 }, { 4, 5 },
            { 6, 1 }, { 6, 3 }, { 6, 5 }
        };

        std::set<std::pair<int, int>> vpc
        {
            { 2, 2 }, { 2, 5 }, { 2, 6 },
            { 3, 2 }, { 3, 5 }, { 3, 6 },
            { 4, 2 }, { 4, 5 }, { 4, 6 }
        };

        auto dsu = Dsu{ static_cast<int>(n * m) };

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (j + 1 < m)
                {
                    if (const auto it = vpr.find({ grid[i][j], grid[i][j + 1] }); it != std::end(vpr))
                    {
                        dsu.un(m * i + j, m * i + j + 1);
                    }
                }

                if (i + 1 < n)
                {
                    if (const auto it = vpc.find({ grid[i][j], grid[i + 1][j] } ); it != std::end(vpc))
                    {
                        dsu.un(m * i + j, m * (i + 1) + j);
                    }
                }
            }
        }

        return dsu.same(0, n * m - 1);
    }
};
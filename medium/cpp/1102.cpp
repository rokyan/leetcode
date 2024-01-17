// https://leetcode.com/problems/path-with-maximum-minimum-value/description/

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
    int maximumMinimumPath(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::pair<int, int>> sorted;
        sorted.reserve(n * m);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                sorted.push_back({ grid[i][j], i * m + j });
            }
        }

        std::sort(std::begin(sorted), std::end(sorted), std::greater<>{});

        dsu meow{ static_cast<int>(n * m) };

        std::array<int, 4> di{ 1, 0, -1, 0 };
        std::array<int, 4> dj{ 0, -1, 0, 1 };

        for (const auto& e : sorted)
        {
            const auto i = e.second / m;
            const auto j = e.second % m;

            for (auto d = 0; d < 4; d++)
            {
                const auto ni = i + di[d];
                const auto nj = j + dj[d];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[i][j] <= grid[ni][nj])
                {
                    const auto s = ni * m + nj;

                    meow.un(e.second, s);
                }
            }

            if (meow.find(0) == meow.find(n * m - 1))
            {
                return e.first;
            }
        }

        return -1;
    }
};
// https://leetcode.com/problems/regions-cut-by-slashes/description/

class Solution
{
private:
    class dsu
    {
    public:
        dsu(int n)
        {
            parent.resize(n);
            size.resize(n);

            for (auto v = 0; v < n; v++)
            {
                parent[v] = v;
                size[v] = 1;
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

        bool un(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return false;
            }

            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
            }

            return true;
        }

        int un_cnt()
        {
            std::unordered_set<int> un;

            for (auto v = 0; v < std::size(parent); v++)
            {
                un.insert(find(v));
            }

            return std::size(un);
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    int regionsBySlashes(std::vector<std::string>& grid)
    {
        const auto n = static_cast<int>(std::size(grid));

        dsu meow{ 4 * n * n };

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                const auto p = 4 * (i * n + j);
                
                if (grid[i][j] == ' ')
                {
                    meow.un(p, p + 1);
                    meow.un(p + 1, p + 2);
                    meow.un(p + 2, p + 3);
                    meow.un(p + 3, p);
                }
                else if (grid[i][j] == '/')
                {
                    meow.un(p + 1, p + 2);
                    meow.un(p + 3, p);
                }
                else if (grid[i][j] == '\\')
                {
                    meow.un(p, p + 1);
                    meow.un(p + 2, p + 3);
                }

                if (j + 1 < n)
                {
                    const auto np = 4 * (i * n + j + 1);
                    meow.un(p + 1, np + 3);
                }

                if (i + 1 < n)
                {
                    const auto np = 4 * ((i + 1) * n + j);
                    meow.un(p + 2, np);
                }
            }
        }

        return meow.un_cnt();
    }
};
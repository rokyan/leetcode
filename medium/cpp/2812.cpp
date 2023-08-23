// https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/

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

            return parent[v] = find(parent[v]);
        }

        void un(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return;
            }

            if (size[u] >= size[v])
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

        bool same(int u, int v)
        {
            return find(u) == find(v);
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid)
    {
        const auto n = static_cast<int>(std::size(grid));

        std::vector<std::vector<int>> dist(n, std::vector<int>(n, -1));

        std::queue<std::pair<int, int>> q;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({ i , j });
                }
            }
        }

        std::array<int, 4> dr{ 0, -1, 0, 1 };
        std::array<int, 4> dc{ 1, 0, -1, 0 };

        std::vector<std::pair<int, std::pair<int, int>>> order;
        order.reserve(n * n);

        while (!q.empty())
        {
            const auto st = q.front();
            q.pop();

            order.push_back({ dist[st.first][st.second], st });

            for (auto d = 0; d < 4; d++)
            {
                const auto next = std::make_pair(st.first + dr[d], st.second + dc[d]);

                if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n &&
                    dist[next.first][next.second] == -1)
                {
                    dist[next.first][next.second] = dist[st.first][st.second] + 1;
                    q.push(next);
                }
            }
        }

        std::sort(std::begin(order), std::end(order), std::greater<>{});

        std::vector<std::vector<char>> can(n, std::vector<char>(n));

        auto res = 0;

        dsu my_dsu(n * n);

        for (const auto& e : order)
        {
            const auto r = e.second.first;
            const auto c = e.second.second;

            can[r][c] = true;

            for (auto d = 0; d < 4; d++)
            {
                const auto rr = r + dr[d];
                const auto cc = c + dc[d];

                if (rr >= 0 && rr < n && cc >= 0 && cc < n && can[rr][cc])
                {
                    my_dsu.un(r * n + c, rr * n + cc);
                }
            }

            if (my_dsu.same(0, n * n - 1))
            {
                res = e.first;
                break;
            }
        }

        return res;
    }
};
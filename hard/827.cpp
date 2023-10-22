// https://leetcode.com/problems/making-a-large-island/description/

class Solution
{
public:
    int largestIsland(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> color(n, std::vector<int>(m, -1));

        auto cur_color = 0;

        std::array<int, 4> dr{ 1, 0, -1, 0 };
        std::array<int, 4> dc{ 0, -1, 0, 1 };

        std::unordered_map<int, int> cnt;

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] && color[i][j] == -1)
                {
                    std::queue<std::pair<int, int>> q;
                    q.push({ i, j });
                    color[i][j] = cur_color;

                    auto tot = 0;

                    while (!q.empty())
                    {
                        const auto [r, c] = q.front();
                        q.pop();

                        tot++;

                        for (auto d = 0; d < 4; d++)
                        {
                            const auto nr = r + dr[d];
                            const auto nc = c + dc[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] && color[nr][nc] == -1)
                            {
                                color[nr][nc] = cur_color;
                                q.push({ nr, nc });
                            }
                        }
                    }

                    cnt[cur_color] = tot;
                    cur_color++;
                    res = std::max(res, tot);
                }
            }
        }

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    std::unordered_set<int> un;

                    for (auto d = 0; d < 4; d++)
                    {
                        const auto nr = i + dr[d];
                        const auto nc = j + dc[d];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && color[nr][nc] != -1)
                        {
                            un.insert(color[nr][nc]);
                        }
                    }

                    auto tot = 1;

                    for (auto&& e : un)
                    {
                        tot += cnt[e];
                    }

                    res = std::max(res, tot);
                }
            }
        }

        return res;
    }
};
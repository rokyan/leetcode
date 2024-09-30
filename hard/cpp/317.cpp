// https://leetcode.com/problems/shortest-distance-from-all-buildings/description/

class Solution
{
public:
    int shortestDistance(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::array<int, 4> dr{ 1, 0, -1, 0 };
        std::array<int, 4> dc{ 0, -1, 0, 1 };

        auto it = 0;

        std::vector<std::vector<int>> tot(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dst(n, std::vector<int>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    std::queue<std::pair<int, int>> q;
                    dst[i][j] = 0;
                    q.push({ i, j });

                    while (!q.empty())
                    {
                        const auto [r, c] = q.front();
                        q.pop();

                        for (auto d = 0; d < 4; d++)
                        {
                            const auto nr = r + dr[d];
                            const auto nc = c + dc[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == -it)
                            {
                                grid[nr][nc] = -it - 1;
                                dst[nr][nc] = dst[r][c] + 1;
                                tot[nr][nc] += dst[nr][nc];
                                q.push({ nr, nc });
                            }
                        }
                    }

                    it++;
                }
            }
        }

        auto res = -1;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] == -it)
                {
                    res = res == -1 ? tot[i][j] : std::min(res, tot[i][j]);
                }
            }
        }

        return res;
    }
}; 
class Solution
{
public:
    int maxAreaOfIsland(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::array<int, 4> drow{1, 0, -1, 0};
        std::array<int, 4> dcol{0, -1, 0, 1};

        std::vector<std::vector<char>> visited(n, std::vector<char>(m));

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    visited[i][j] = true;

                    std::queue<std::pair<int, int>> q;
                    q.push({i, j});

                    auto compSize = 0;

                    while (!q.empty())
                    {
                        const auto [r, c] = q.front();
                        q.pop();

                        compSize++;

                        for (auto d = 0; d < 4; d++)
                        {
                            const auto nr = r + drow[d];
                            const auto nc = c + dcol[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                                && grid[nr][nc] && !visited[nr][nc])
                            {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }

                    res = std::max(res, compSize);
                }
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

class Solution
{
public:
    int shortestPath(const std::vector<std::vector<int>>& grid, int k)
    {
        const int n = std::size(grid);
        const int m = std::size(grid.front());

        std::array<int, 4> dr{1, 0, -1, 0};
        std::array<int, 4> dc{0, -1, 0, 1};

        std::queue<std::tuple<int, int, int>> q;
        q.push({0, 0, k});

        std::vector<std::vector<std::vector<int>>> distance(n,
            std::vector<std::vector<int>>(m, std::vector<int>(k + 1, -1)));
        distance[0][0][k] = 0;

        while (!q.empty())
        {
            const auto [r, c, rem] = q.front();
            q.pop();

            for (auto d = 0; d < 4; d++)
            {
                const auto nr = r + dr[d];
                const auto nc = c + dc[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    if (grid[nr][nc] && rem && distance[nr][nc][rem - 1] == -1)
                    {
                        distance[nr][nc][rem - 1] = distance[r][c][rem] + 1;
                        q.push({nr, nc, rem - 1});
                    }

                    if (!grid[nr][nc] && distance[nr][nc][rem] == -1)
                    {
                        distance[nr][nc][rem] = distance[r][c][rem] + 1;
                        q.push({nr, nc, rem});
                    }
                }
            }
        }

        int res = -1;

        for (int d = 0; d <= k; d++)
        {
            if (distance[n - 1][m - 1][d] != -1 &&
                (res == -1 || res > distance[n - 1][m - 1][d]))
            {
                res = distance[n - 1][m - 1][d];
            }
        }

        return res;
    }
};
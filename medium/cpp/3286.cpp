// https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/

class Solution
{
public:
    bool findSafeWalk(const std::vector<std::vector<int>>& grid, int health)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::array<int, 4> drow{1, 0, -1, 0};
        std::array<int, 4> dcol{0, -1, 0, 1};

        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
        dist[0][0] = 0;

        std::deque<std::pair<int, int>> q;
        q.push_back({0, 0});

        while (!q.empty())
        {
            const auto [row, col] = q.front();
            q.pop_front();

            for (auto d = 0; d < 4; d++)
            {
                const auto nrow = row + drow[d];
                const auto ncol = col + dcol[d];

                if (nrow >= 0 && nrow < n
                    && ncol >= 0 && ncol < m
                    && dist[nrow][ncol] == -1)
                {
                    dist[nrow][ncol] = dist[row][col] + grid[nrow][ncol];

                    if (grid[nrow][ncol] == 0)
                    {
                        q.push_front({nrow, ncol});
                    }
                    else
                    {
                        q.push_back({nrow, ncol});
                    }
                }
            }
        }

        return dist[n - 1][m - 1] < health - grid[0][0];
    }
};
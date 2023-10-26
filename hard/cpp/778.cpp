// https://leetcode.com/problems/swim-in-rising-water/description/

class Solution
{
public:
    int swimInWater(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        auto lo = grid[0][0];
        auto hi = n * m;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (solve(grid, mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }

private:
    bool solve(const std::vector<std::vector<int>>& grid, int level)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<char>> vis(n, std::vector<char>(m));

        std::array<int, 4> drow{ 1, 0, -1, 0 };
        std::array<int, 4> dcol{ 0, -1, 0, 1 };

        std::queue<std::pair<int, int>> q;
        q.push({ 0, 0 });
        vis[0][0] = true;

        while (!q.empty())
        {
            const auto [row, col] = q.front();
            q.pop();

            for (auto d = 0; d < 4; d++)
            {
                const auto nrow = row + drow[d];
                const auto ncol = col + dcol[d];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] <= level)
                {
                    vis[nrow][ncol] = true;
                    q.push({ nrow, ncol });
                }
            }
        }

        return vis[n - 1][m - 1];
    }
};
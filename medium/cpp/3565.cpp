// https://leetcode.com/problems/sequential-grid-path-cover/description/

class Solution
{
public:
    std::vector<std::vector<int>> findPath(const std::vector<std::vector<int>>& grid, int k)
    {
        std::vector<std::vector<int>> res;

        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<vector<char>> visited(n, std::vector<char>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (solve(i, j, n, m, res, grid, visited, 0))
                {
                    return res;
                }
            }
        }

        return res;
    }

private:
    bool solve(int i, int j, int n, int m,
        std::vector<std::vector<int>>& res,
        const std::vector<std::vector<int>>& grid,
        std::vector<std::vector<char>>& visited,
        int last = -1)
    {
        if (i < 0 || i == n || j < 0 || j == m || visited[i][j])
        {
            return false;
        }

        if (grid[i][j] != 0 && grid[i][j] != last + 1)
        {
            return false;
        }

        res.push_back({i, j});
        visited[i][j] = true;

        if (grid[i][j] != 0)
        {
            last = grid[i][j];
        }

        if (std::size(res) == n * m)
        {
            return true;
        }

        if (solve(i - 1, j, n, m, res, grid, visited, last))
        {
            return true;
        }

        if (solve(i + 1, j, n, m, res, grid, visited, last))
        {
            return true;
        }

        if (solve(i, j - 1, n, m, res, grid, visited, last))
        {
            return true;
        }

        if (solve(i, j + 1, n, m, res, grid, visited, last))
        {
            return true;
        }

        res.pop_back();
        visited[i][j] = false;

        return false;
    }
};
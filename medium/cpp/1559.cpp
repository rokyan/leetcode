// https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

class Solution
{
private:
    static constexpr std::array<int, 4> di{ 1, 0, -1, 0 };
    static constexpr std::array<int, 4> dj{ 0, -1, 0, 1 };

public:
    bool containsCycle(vector<vector<char>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<char>> visited(n, std::vector<char>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (!visited[i][j] && find(i, j, -1, -1, n, m, grid, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool find(int i, int j, int pi, int pj, int n, int m, const vector<vector<char>>& grid, std::vector<std::vector<char>>& visited)
    {
        visited[i][j] = true;

        for (auto d = 0; d < 4; d++)
        {
            const auto ni = i + di[d];
            const auto nj = j + dj[d];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[i][j] == grid[ni][nj] && (ni != pi || nj != pj))
            {
                if (visited[ni][nj] || find(ni, nj, i, j, n, m, grid, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
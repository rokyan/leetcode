// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

class Solution
{
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> memo(n, std::vector<int>(m, -1));

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (memo[i][j] == -1)
                {
                    dfs(i, j, n, m, -1, memo, grid);
                }

                if (j == 0)
                {
                    res = std::max(res, memo[i][j]);
                }
            }
        }

        return res;
    }

private:
    int dfs(int i, int j, int n, int m, int prev, std::vector<std::vector<int>>& memo, const std::vector<std::vector<int>>& grid)
    {
        if (i < 0 || i == n || j < 0 || j == m || prev >= grid[i][j])
        {
            return 0;
        }

        if (memo[i][j] == -1)
        {
            memo[i][j] = 0;
            memo[i][j] = std::max(memo[i][j], dfs(i - 1, j + 1, n, m, grid[i][j], memo, grid));
            memo[i][j] = std::max(memo[i][j], dfs(i, j + 1, n, m, grid[i][j], memo, grid));
            memo[i][j] = std::max(memo[i][j], dfs(i + 1, j + 1, n, m, grid[i][j], memo, grid));
        }

        return memo[i][j] + 1;
    }
};
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

class Solution
{
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, - 1));

        auto res = -1;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (dp[i][j] == -1)
                {
                    res = std::max(res, dfs(i, j, n, m, dp, matrix));
                }
            }
        }

        return res;
    }

private:
    int dfs(int i, int j, int n, int m, std::vector<std::vector<int>>& dp, const std::vector<std::vector<int>>& matrix)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        dp[i][j] = 1;

        if (i > 0 && matrix[i - 1][j] > matrix[i][j])
        {
            dp[i][j] = std::max(dp[i][j], 1 + dfs(i - 1, j, n, m, dp, matrix));
        }

        if (j > 0 && matrix[i][j - 1] > matrix[i][j])
        {
            dp[i][j] = std::max(dp[i][j], 1 + dfs(i, j - 1, n, m, dp, matrix));
        }

        if (i + 1 < n && matrix[i + 1][j] > matrix[i][j])
        {
            dp[i][j] = std::max(dp[i][j], 1 + dfs(i + 1, j, n, m, dp, matrix));
        }

        if (j + 1 < m && matrix[i][j + 1] > matrix[i][j])
        {
            dp[i][j] = std::max(dp[i][j], 1 + dfs(i, j + 1, n, m, dp, matrix));
        }

        return dp[i][j];
    }
};
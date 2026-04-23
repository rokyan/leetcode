// https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/

class Solution
{
public:
    int minCost(const std::vector<std::vector<int>>& grid)
    {
        const int n = grid.size();
        const int m = grid.front().size();

        std::vector<std::vector<std::vector<char>>> dp(n,
            std::vector<std::vector<char>>(m, std::vector<char>(1024, false)));
        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    for (int val = 0; val < 1024; val++)
                    {
                        if (dp[i - 1][j][val])
                        {
                            dp[i][j][val ^ grid[i][j]] = true;
                        }
                    }
                }

                if (j > 0)
                {
                    for (int val = 0; val < 1024; val++)
                    {
                        if (dp[i][j - 1][val])
                        {
                            dp[i][j][val ^ grid[i][j]] = true;
                        }
                    }
                }
            }
        }

        for (int val = 0; val < 1024; val++)
        {
            if (dp[n - 1][m - 1][val])
            {
                return val;
            }
        }

        return -1;
    }
};
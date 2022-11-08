// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        const int n = std::size(grid);
        const int m = std::size(grid.front());
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
         
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                dp[row][col] = grid[row][col];
                
                if (row > 0 && col > 0)
                {
                    dp[row][col] += std::min(dp[row - 1][col], dp[row][col - 1]);
                }
                else if (row > 0)
                {
                    dp[row][col] += dp[row - 1][col];
                }
                else if (col > 0)
                {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }
        
        return dp[n - 1][m - 1];
    }
};
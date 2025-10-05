class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        const int n = std::size(obstacleGrid);
        const int m = std::size(obstacleGrid.front());
        
        std::vector<std::vector<int>> dp(n);
        
        for (int row = 0; row < n; row++)
        {
            dp[row].resize(m);
        }
                
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (obstacleGrid[row][col] == 1)
                {
                    continue;
                }
                
                if (row == 0 && col == 0)
                {
                    dp[row][col] = 1;
                    continue;
                }
                
                if (row > 0 && !obstacleGrid[row - 1][col])
                {
                    dp[row][col] += dp[row - 1][col];
                }
                
                if (col > 0 && !obstacleGrid[row][col - 1])
                {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }
        
        return dp[n - 1][m - 1];
    }
};
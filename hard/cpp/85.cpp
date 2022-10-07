// https://leetcode.com/problems/maximal-rectangle/

class Solution
{
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j] - '0';
        }
        
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                dp[i][j] = matrix[i][j] == '1' ? dp[i - 1][j] + 1 : 0;
            }
        }

        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = j;
                int height = dp[i][j];
                
                while (k >= 0 && dp[i][k] > 0)
                {
                    height = std::min(height, dp[i][k]);
                    ans = std::max(ans, height * (j - k + 1));
                    k--;
                }
            }
        }
        
        return ans;
    }
};
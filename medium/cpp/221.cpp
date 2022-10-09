// https://leetcode.com/problems/maximal-square/

class Solution
{
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        
        auto ans = 0;
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                    }
                    
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
        
        return ans * ans;
    }
};
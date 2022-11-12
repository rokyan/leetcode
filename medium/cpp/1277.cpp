// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution
{
public:
    int countSquares(std::vector<std::vector<int>>& matrix)
    {
        const std::size_t n = std::size(matrix);
        const std::size_t m = std::size(matrix.front());   
        
        int result = 0;
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        
        for (std::size_t row = 0; row < n; row++)
        {           
            for (std::size_t col = 0; col < m; col++)
            {
                if (matrix[row][col] == 1)
                {
                    dp[row][col] = 1;
                                       
                    if (row > 0 && col > 0)
                    {
                       dp[row][col] += std::min(dp[row - 1][col - 1], std::min(dp[row][col - 1], dp[row - 1][col]));
                    }
                    
                    result += dp[row][col];
                }
            }
        }
               
        return result;
    }
};
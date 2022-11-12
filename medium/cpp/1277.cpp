// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution
{
public:
    int countSquares(std::vector<std::vector<int>>& matrix)
    {
        const std::size_t m = std::size(matrix);
        const std::size_t n = std::size(matrix.front());
        
        std::vector<std::vector<int>> onesInRow(m);
        
        for (std::size_t row = 0; row < m; row++)
        {
            onesInRow[row].resize(n);
            
            for (std::size_t col = 0; col < n; col++)
            {
                if (matrix[row][col] == 1)
                {
                    onesInRow[row][col] = 1;
                    
                    if (col > 0)
                    {
                        onesInRow[row][col] += onesInRow[row][col - 1];
                    }
                }
            }
        }
        
        std::vector<std::vector<int>> onesInCol(m);
        
        for (std::size_t row = 0; row < m; row++)
        {
            onesInCol[row].resize(n);
            
            for (std::size_t col = 0; col < n; col++)
            {
                if (matrix[row][col] == 1)
                {
                    onesInCol[row][col] = 1;
                    
                    if (row > 0)
                    {
                        onesInCol[row][col] += onesInCol[row - 1][col];
                    }
                }
            }
        }       
        
        int result = 0;
        
        std::vector<std::vector<int>> dp(m);
        
        for (std::size_t row = 0; row < m; row++)
        {
            dp[row].resize(n);
            
            for (std::size_t col = 0; col < n; col++)
            {
                if (matrix[row][col] == 1)
                {
                    dp[row][col] = 1;
                                       
                    if (row > 0 && col > 0)
                    {
                       dp[row][col] += std::min(dp[row - 1][col - 1], std::min(onesInRow[row][col - 1], onesInCol[row - 1][col]));
                    }
                    
                    result += dp[row][col];
                }
            }
        }
               
        return result;
    }
};  
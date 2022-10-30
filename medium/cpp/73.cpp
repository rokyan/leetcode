// https://leetcode.com/problems/set-matrix-zeroes/

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        const std::size_t n = std::size(matrix);
        const std::size_t m = std::size(matrix.front());
               
        bool has_zero_in_first_row = false;
        
        for (std::size_t j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
            {
                has_zero_in_first_row = true;
                break;
            }
        }
        
        bool has_zero_in_first_col = false;
        
        for (std::size_t i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                has_zero_in_first_col = true;
                break;
            }
        }
        
        for (std::size_t i = 1; i < n; i++)
        {
            bool has_zero = false;
            
            for (std::size_t j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    has_zero = true;
                    break;
                }
            }
            
            if (has_zero)
            {
                matrix[i][0] = 0;
            }
        }
        
        for (std::size_t j = 1; j < m; j++)
        {
            bool has_zero = false;
            
            for (std::size_t i = 0; i < n; i++)
            {
                if (matrix[i][j] == 0)
                {
                    has_zero = true;
                    break;
                }
            }
            
            if (has_zero)
            {
                matrix[0][j] = 0;
            }
        }
        
        for (std::size_t i = 1; i < n; i++)
        {
            for (std::size_t j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (has_zero_in_first_row)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        
        if (has_zero_in_first_col)
        {
            for (std::size_t i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
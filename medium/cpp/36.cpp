// https://leetcode.com/problems/valid-sudoku/

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        std::vector<int> digits(10);
        
        const std::size_t board_size = std::size(board);
        
        for (std::size_t row = 0; row < board_size; row++)
        {
            std::fill(std::begin(digits), std::end(digits), 0);
            
            for (std::size_t col = 0; col < board_size; col++)
            {
                if (board[row][col] == '.')
                {
                    continue;
                }
                
                const int digit = board[row][col] - '0';
                
                if (digits[digit])
                {
                    return false;
                }
                
                digits[digit] = 1;
            }
        }
        
        for (std::size_t col = 0; col < board_size; col++)
        {
            std::fill(std::begin(digits), std::end(digits), 0);
            
            for (std::size_t row = 0; row < board_size; row++)
            {
                if (board[row][col] == '.')
                {
                    continue;
                }
                
                const int digit = board[row][col] - '0';
                
                if (digits[digit])
                {
                    return false;
                }
                
                digits[digit] = 1;
            }
        }
        
        for (std::size_t row = 0; row < board_size; row += 3)
        {
            for (std::size_t col = 0; col < board_size; col += 3)
            {
                std::fill(std::begin(digits), std::end(digits), 0);
                
                for (std::size_t rrow = row; rrow < row + 3; rrow++)
                {
                    for (std::size_t ccol = col; ccol < col + 3; ccol++)
                    {
                        if (board[rrow][ccol] == '.')
                        {
                            continue;
                        }
                        
                        const int digit = board[rrow][ccol] - '0';
                        
                        if (digits[digit])
                        {
                            return false;
                        }

                        digits[digit] = 1;
                    }
                }
            }
        }
        
        return true;
    }
};
// https://leetcode.com/problems/battleships-in-a-board/description/

class Solution
{
public:
    int countBattleships(vector<vector<char>>& board)
    {       
        const auto rows = std::size(board);
        const auto cols = std::size(board.front());
        
        auto counter = 0;
        
        for (auto i = 0; i < rows; ++i)
        {
            for (auto j = 0; j < cols; ++j)
            {
                const auto up = (i == 0) || (board[i - 1][j] == '.');
                const auto lf = (j == 0) || (board[i][j - 1] == '.');
                
                if (up && lf && (board[i][j] == 'X'))
                {
                    ++counter;
                }
            }
        }
        
        return counter;
    }
};
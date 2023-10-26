// https://leetcode.com/problems/design-tic-tac-toe/description/

class TicTacToe
{
public:
    TicTacToe(int n)
        : n{ n }
    {
        board.resize(n, std::vector<int>(n));
    }
    
    int move(int row, int col, int player)
    {
        board[row][col] = player;

        auto check = true;

        for (auto j = 0; j < n && check; j++)
        {
            if (board[row][j] != player)
            {
                check = false;
            }
        }

        if (check)
        {
            return player;
        }

        check = true;

        for (auto i = 0; i < n && check; i++)
        {
            if (board[i][col] != player)
            {
                check = false;
            }
        }

        if (check)
        {
            return player;
        }

        if (row == col)
        {
            check = true;

            for (auto i = 0; i < n && check; i++)
            {
                if (board[i][i] != player)
                {
                    check = false;
                }
            }

            if (check)
            {
                return player;
            }
        }

        if (row == n - col - 1)
        {
            check = true;

            for (auto i = 0; i < n && check; i++)
            {
                if (board[i][n - i - 1] != player)
                {
                    check = false;
                }
            }

            if (check)
            {
                return player;
            }
        }

        return 0;
    }

private:
    int n;
    std::vector<std::vector<int>> board;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
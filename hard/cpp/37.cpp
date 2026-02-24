// https://leetcode.com/problems/sudoku-solver/description/

class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>>& board)
    {
        std::vector<int> rows(9);
        std::vector<int> cols(9);
        std::vector<std::vector<int>> sq(3, std::vector<int>(3));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    rows[i] |= 1 << (board[i][j] - '0');
                    cols[j] |= 1 << (board[i][j] - '0');
                    sq[i / 3][j / 3] = 1 << (board[i][j] - '0');
                }
            }
        }

        fill(0, 0, board, rows, cols, sq);
    }

private:
    bool fill(
        int r, int c,
        std::vector<std::vector<char>>& board,
        std::vector<int>& rows,
        std::vector<int>& cols,
        std::vector<std::vector<int>>& sq)
    {
        if (r == 9 && c == 0)
        {
            return true;
        }

        if (board[r][c] != '.')
        {
            int nc = c + 1;
            int nr = r;

            if (nc == 9)
            {
                nr++;
                nc = 0;
            }

            return fill(nr, nc, board, rows, cols, sq);
        }

        for (int d = 1; d <= 9; d++)
        {
            if ((rows[r] & (1 << d)) == 0
                && (cols[c] & (1 << d)) == 0
                && (sq[r / 3][c / 3] & (1 << d)) == 0)
            {
                rows[r] |= 1 << d;
                cols[c] |= 1 << d;
                sq[r / 3][c / 3] |= 1 << d;
                board[r][c] = '0' + d;

                if (fill(r, c, board, rows, cols, sq))
                {
                    return true;
                }

                rows[r] ^= 1 << d;
                cols[c] ^= 1 << d;
                sq[r / 3][c / 3] ^= 1 << d;
                board[r][c] = '.';
            }
        }

        return false;
    }
};
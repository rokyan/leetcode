// https://leetcode.com/problems/minesweeper/description/

class Solution
{
public:
    std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board, std::vector<int>& click)
    {
        std::array<int, 8> di{ 0, 1, 1, 1, 0, -1, -1, -1 };
        std::array<int, 8> dj{ 1, 1, 0, -1, -1, -1, 0, 1 };

        const auto n = std::size(board);
        const auto m = std::size(board.front());

        handle_click(click[0], click[1], n, m, di, dj, board);

        return board;
    }

private:
    void handle_click(int i, int j, int n, int m,
        const std::array<int, 8>& di, const std::array<int, 8>& dj, std::vector<std::vector<char>>& board)
    {
        if (i < 0 || i == n || j < 0 || j == m)
        {
            return;
        }

        if (board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return;
        }

        if (board[i][j] == 'E')
        {
            auto cnt = 0;

            for (auto d = 0; d < 8; d++)
            {
                const auto ni = i + di[d];
                const auto nj = j + dj[d];

                if (ni >= 0 && nj >= 0 && ni < n && nj < m && board[ni][nj] == 'M')
                {
                    cnt++;
                }
            }

            if (cnt > 0)
            {
                board[i][j] = '0' + cnt;
            }
            else
            {
                board[i][j] = 'B';

                for (auto d = 0; d < 8; d++)
                {
                    handle_click(i + di[d], j + dj[d], n, m, di, dj, board);
                }
            }
        }
    }
};
// https://leetcode.com/problems/surrounded-regions/description/

class Solution
{
public:
    void solve(std::vector<std::vector<char>>& board)
    {
        const auto n = std::size(board);
        const auto m = std::size(board.front());

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    if (board[i][j] == 'O')
                    {
                        bfs(i, j, board);
                    }
                }
            }
        }

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (board[i][j] == 'R')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void bfs(int r, int c, std::vector<std::vector<char>>& board)
    {
        const auto n = std::size(board);
        const auto m = std::size(board.front());

        std::queue<std::pair<int, int>> q;
        q.push({r, c});
        board[r][c] = 'R';

        std::array<int, 4> dr{ 1, 0, -1, 0 };
        std::array<int, 4> dc{ 0, -1, 0, 1 };

        while (!q.empty())
        {
            const auto [cr, cc] = q.front();
            q.pop();

            for (auto d = 0; d < 4; d++)
            {
                const auto nr = cr + dr[d];
                const auto nc = cc + dc[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O')
                {
                    board[nr][nc] = 'R';
                    q.push({nr, nc});
                }
            }
        }
    }
};
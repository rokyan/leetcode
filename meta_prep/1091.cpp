class Solution
{
public:
    int shortestPathBinaryMatrix(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);

        if (grid[0][0] || grid[n - 1][n - 1])
        {
            return -1;
        }

        std::vector<std::vector<int>> dst(n, std::vector<int>(n, -1));
        dst[0][0] = 1;

        std::queue<std::pair<int, int>> q;
        q.push({0, 0});

        std::array<int, 8> drow{-1, -1, 0, 1, 1, 1, 0, -1};
        std::array<int, 8> dcol{0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty() && dst[n - 1][n - 1] == -1)
        {
            auto [cur_row, cur_col] = q.front();
            q.pop();

            for (auto d = 0; d < 8; d++)
            {
                const auto row = cur_row + drow[d];
                const auto col = cur_col + dcol[d];

                if (row >= 0 && row < n && col >= 0 && col < n &&
                    grid[row][col] == 0 && dst[row][col] == -1)
                {
                    dst[row][col] = dst[cur_row][cur_col] + 1;
                    q.push({ row, col });
                }
            }
        }

        return dst[n - 1][n - 1];
    }
};
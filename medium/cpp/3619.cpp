// https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/

class Solution
{
public:
    int countIslands(vector<vector<int>>& grid, int k)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<char>> visited(n, std::vector<char>(m));

        std::array<int, 4> drow{1, 0, -1, 0};
        std::array<int, 4> dcol{0, -1, 0, 1};

        auto res = 0;

        for (auto r = 0; r < n; r++)
        {
            for (auto c = 0; c < m; c++)
            {
                if (grid[r][c] && !visited[r][c])
                {
                    std::queue<std::pair<int, int>> q;
                    q.push({r, c});
                    visited[r][c] = true;
                    auto sum = 0;

                    while (!q.empty())
                    {
                        auto [curR, curC] = q.front();
                        q.pop();
                        sum += grid[curR][curC];
                        sum %= k;

                        for (auto d = 0; d < 4; d++)
                        {
                            const auto nextR = curR + drow[d];
                            const auto nextC = curC + dcol[d];

                            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m
                                && !visited[nextR][nextC] && grid[nextR][nextC])
                            {
                                visited[nextR][nextC] = true;
                                q.push({nextR, nextC});
                            }
                        }
                    }

                    res += sum % k == 0;
                }
            }
        }

        return res;
    }
};
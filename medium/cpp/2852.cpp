// https://leetcode.com/problems/sum-of-remoteness-of-all-cells/description/

class Solution
{
public:
    long long sumRemoteness(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);

        std::array<int, 4> dr { 1, 0, -1, 0 };
        std::array<int, 4> dc { 0, -1, 0, 1 };

        std::vector<std::vector<int>> comp(n, std::vector<int>(n, -1));
        std::vector<long long> x;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (comp[i][j] == -1 && grid[i][j] != -1)
                {
                    std::queue<std::pair<int, int>> q;
                    q.push({ i, j });
                    comp[i][j] = std::size(x);
                    auto s = 0LL;

                    while (!q.empty())
                    {
                        const auto [r, c] = q.front();
                        q.pop();
                        s += grid[r][c];

                        for (auto d = 0; d < 4; d++)
                        {
                            const auto nr = r + dr[d];
                            const auto nc = c + dc[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < n && comp[nr][nc] == -1 &&
                                grid[nr][nc] != -1)
                            {
                                comp[nr][nc] = std::size(x);
                                q.push({ nr, nc });
                            }
                        }
                    }

                    x.push_back(s);
                }
            }
        }

        const auto tot = std::accumulate(std::cbegin(x), std::cend(x), 0LL);

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (comp[i][j] != -1)
                {
                    res += tot - x[comp[i][j]];
                }
            }
        }

        return res;
    }
};
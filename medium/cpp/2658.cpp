// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

class Solution
{
public:
    int findMaxFish(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<char>> used(n, std::vector<char>(m, -1));

        std::vector<std::pair<int, int>> ad { { 1, 0 }, { -1, 0 }, { 0, 1}, {0, -1 } };

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (used[i][j] == -1 && grid[i][j] > 0)
                {
                    std::queue<std::pair<int, int>> q;
                    q.push({ i, j });
                    used[i][j] = true;

                    auto s = grid[i][j];

                    while (!q.empty())
                    {
                        const auto st = q.front();
                        q.pop();

                        for (auto k = 0; k < 4; k++)
                        {
                            std::pair<int, int> nst = { st.first + ad[k].first, st.second + ad[k].second };

                            if (nst.first >= 0 && nst.first < n && nst.second >= 0 && nst.second < m &&
                                grid[nst.first][nst.second] > 0 && used[nst.first][nst.second] == -1)
                            {
                                used[nst.first][nst.second] = 1;
                                s += grid[nst.first][nst.second];
                                q.push(nst);
                            }
                        }
                    }

                    res = std::max(res, s);
                }
            }
        }

        return res;
    }
};
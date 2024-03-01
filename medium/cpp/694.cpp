// https://leetcode.com/problems/number-of-distinct-islands/description/

class Solution
{
public:
    int numDistinctIslands(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<char>> visited(n, std::vector<char>(m));

        std::array<int, 4> di{ 1, 0, -1, 0 };
        std::array<int, 4> dj{ 0, -1, 0, 1 };

        std::set<std::vector<std::pair<int, int>>> distinct;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    visited[i][j] = true;

                    std::queue<std::pair<int, int>> q;
                    q.push({ i, j });

                    std::vector<std::pair<int, int>> all;

                    while (!q.empty())
                    {
                        const auto [pi, pj] = q.front();
                        all.push_back(q.front());
                        q.pop();

                        for (auto d = 0; d < 4; d++)
                        {
                            const auto ni = pi + di[d];
                            const auto nj = pj + dj[d];

                            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && grid[ni][nj])
                            {
                                visited[ni][nj] = true;
                                q.push({ ni, nj });
                            }
                        }
                    }

                    auto si = all.front().first;
                    auto sj = all.front().second;

                    for (const auto& e : all)
                    {
                        si = std::min(si, e.first);
                        sj = std::min(sj, e.second);
                    }

                    for (auto& e : all)
                    {
                        e.first -= si;
                        e.second -= sj;
                    }

                    std::sort(std::begin(all), std::end(all));

                    distinct.insert(all);
                }
            }
        }

        return std::size(distinct);
    }
};
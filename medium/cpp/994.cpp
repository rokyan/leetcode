// https://leetcode.com/problems/rotting-oranges/description/

class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>>& grid)
    {
        std::queue<std::tuple<int, int, int>> q;

        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        auto rem = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.emplace(i, j, 0);
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 1)
                {
                    rem++;
                }
            }
        }

        std::array<int, 4> di{ 0, -1, 0, 1 };
        std::array<int, 4> dj{ 1, 0, -1, 0 };

        auto minutes = 0;

        while (!q.empty())
        {
            const auto [i, j, t] = q.front();
            q.pop();

            minutes = t;

            for (auto d = 0; d < 4; d++)
            {
                const auto ni = i + di[d];
                const auto nj = j + dj[d];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1)
                {
                    grid[ni][nj] = 2;
                    rem--;
                    q.emplace(ni, nj, t + 1);
                }
            }
        }

         return rem == 0 ? minutes : -1;
    }
};
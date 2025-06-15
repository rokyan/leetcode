// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

class Solution
{
public:
    std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>>& heights)
    {
        const int n = std::size(heights);
        const int m = std::size(heights.front());

        std::array<int, 4> drow{1, 0, -1, 0};
        std::array<int, 4> dcol{0, -1, 0, 1};

        std::vector<std::vector<int>> color(n, std::vector<int>(m));

        std::queue<std::pair<int, int>> q;

        for (auto r = 0; r < n; r++)
        {
            q.push({r, 0});
            color[r][0] = 1;
        }

        for (auto c = 1; c < m; c++)
        {
            q.push({0, c});
            color[0][c] = 1;
        }

        while (!q.empty())
        {
            const auto [r, c] = q.front();
            q.pop();

            for (auto d = 0; d < 4; d++)
            {
                const auto nr = r + drow[d];
                const auto nc = c + dcol[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && color[nr][nc] == 0
                    && heights[nr][nc] >= heights[r][c])
                {
                    color[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        std::vector<std::vector<int>> res;

        for (auto r = 0; r < n; r++)
        {
            if (color[r][m - 1] == 1)
            {
                res.push_back({r, m - 1});
            }

            color[r][m - 1] = 2;
            q.push({r, m - 1});
        }

        for (auto c = 0; c < m; c++)
        {
            if (color[n - 1][c] == 1)
            {
                res.push_back({n - 1, c});
            }

            color[n - 1][c] = 2;
            q.push({n - 1, c});
        }

        while (!q.empty())
        {
            const auto [r, c] = q.front();
            q.pop();

            for (auto d = 0; d < 4; d++)
            {
                const auto nr = r + drow[d];
                const auto nc = c + dcol[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && heights[nr][nc] >= heights[r][c]
                    && color[nr][nc] != 2)
                {
                    if (color[nr][nc] == 1)
                    {
                        res.push_back({nr, nc});
                    }

                    color[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }

        return res;
    }
};
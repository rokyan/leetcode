// https://leetcode.com/problems/multi-source-flood-fill/description/

class Solution
{
public:
    std::vector<std::vector<int>> colorGrid(int n, int m,
        const std::vector<std::vector<int>>& sources)
    {
        std::queue<std::pair<int, int>> q;

        std::vector<std::vector<int>> color(n, std::vector<int>(m));

        for (const auto& source : sources)
        {
            q.push({source[0], source[1]});
            color[source[0]][source[1]] = source[2];
        }

        std::vector<std::vector<int>> time(n, std::vector<int>(m));

        std::array<int, 4> dr{0, -1, 0, 1};
        std::array<int, 4> dc{1, 0, -1, 0};

        while (!q.empty())
        {
            const auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                const int nr = r + dr[d];
                const int nc = c + dc[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    if (color[nr][nc] == 0)
                    {
                        color[nr][nc] = color[r][c];
                        time[nr][nc] = time[r][c] + 1;
                        q.push({nr, nc});
                    }
                    else if (time[nr][nc] == time[r][c] + 1)
                    {
                        color[nr][nc] = std::max(color[nr][nc], color[r][c]);
                    }
                }
            }
        }

        return color;
    }
};
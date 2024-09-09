// https://leetcode.com/problems/01-matrix/description/

class Solution
{
public:
    std::vector<std::vector<int>> updateMatrix(const std::vector<std::vector<int>>& mat)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());

        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));

        std::queue<std::pair<int, int>> q;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({ i, j });
                }
            }
        }

        const std::array<int, 4> di{ 1, 0, -1, 0 };
        const std::array<int, 4> dj{ 0, -1, 0, 1 };

        while (!q.empty())
        {
            const auto [i, j] = q.front();
            q.pop();

            for (auto d = 0; d < 4; d++)
            {
                const auto ni = i + di[d];
                const auto nj = j + dj[d];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && dist[ni][nj] == -1)
                {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ ni, nj });
                }
            }
        }

        return dist;
    }
};
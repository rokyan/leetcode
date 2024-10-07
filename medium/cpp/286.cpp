// https://leetcode.com/problems/walls-and-gates/description/

class Solution
{
private:
    static constexpr auto inf = (1LL << 31) - 1;

public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms)
    {
        const auto n = std::size(rooms);
        const auto m = std::size(rooms.front());

        std::queue<std::pair<int, int>> q;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (rooms[i][j] == 0)
                {
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

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && rooms[ni][nj] == inf)
                {
                    rooms[ni][nj] = rooms[i][j] + 1;
                    q.push({ ni, nj });
                }
            }
        }
    }
};
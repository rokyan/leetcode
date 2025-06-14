// https://leetcode.com/problems/snakes-and-ladders/description/

class Solution
{
public:
    int snakesAndLadders(const std::vector<std::vector<int>>& board)
    {
        const int n = std::size(board);

        std::vector<std::pair<int, int>> mapping(n * n + 1);

        for (auto r = n - 1, t = 1, b = 0; r >= 0; r--)
        {
            auto c = (b & 1) ? n - 1 : 0;

            for (auto times = 0; times < n; times++)
            {
                mapping[t++] = {r, c};
                c += (b & 1) ? -1 : 1;
            }

            b ^= 1;
        }

        std::vector<int> dist(n * n + 1, -1);
        dist[1] = 0;

        std::queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            const auto id = q.front();
            q.pop();

            for (auto add = 1; add <= 6 && add + id <= n * n; add++)
            {
                auto nextId = id + add;

                const auto [r, c] = mapping[nextId];

                if (board[r][c] != -1)
                {
                    nextId = board[r][c];
                }

                if (dist[nextId] == -1)
                {
                    dist[nextId] = dist[id] + 1;
                    q.push(nextId);
                }
            }
        }

        return dist.back();
    }
};
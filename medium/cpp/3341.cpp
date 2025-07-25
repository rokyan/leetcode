// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/

class Solution
{
private:
    static constexpr auto inf = 2 * 1000'000'000;

public:
    int minTimeToReach(const std::vector<std::vector<int>>& moveTime)
    {
        const auto n = std::size(moveTime);
        const auto m = std::size(moveTime.front());

        const auto nodesCount = n * m;

        std::vector<int> dist(nodesCount, inf);
        dist[0] = 0;

        std::vector<char> visited(nodesCount);

        std::array<int, 4> drow{1, 0, -1, 0};
        std::array<int, 4> dcol{0, -1, 0, 1};

        for (auto times = 0; times < nodesCount; times++)
        {
            auto v = -1;

            for (auto u = 0; u < nodesCount; u++)
            {
                if (!visited[u] && (v == -1 || dist[u] < dist[v]))
                {
                    v = u;
                }
            }

            visited[v] = true;

            const auto row = v / m;
            const auto col = v % m;

            for (auto d = 0; d < 4; d++)
            {
                const auto nextRow = row + drow[d];
                const auto nextCol = col + dcol[d];

                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m)
                {
                    const auto to = nextRow * m + nextCol;

                    if (!visited[to] && dist[to] > dist[v])
                    {
                        dist[to] = std::max(moveTime[nextRow][nextCol] + 1, dist[v] + 1);
                    }
                }
            }
        }

        return dist[nodesCount - 1];
    }
};
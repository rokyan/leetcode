// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/

class Solution
{
private:
    static constexpr auto inf = 2000'000'000 + 7;

public:
    int minTimeToReach(const std::vector<std::vector<int>>& moveTime)
    {
        const auto n = std::size(moveTime);
        const auto m = std::size(moveTime.front());

        std::set<std::tuple<int, int, int, int>> q;
        q.insert({0, 0, 0, 0});

        std::vector<std::vector<std::vector<int>>> dist(n,
            std::vector<std::vector<int>>(m, std::vector<int>(2, inf)));
        dist[0][0][0] = 0;

        std::vector<std::vector<std::vector<int>>> visited(n,
            std::vector<std::vector<int>>(m, std::vector<int>(2, 0)));
        visited[0][0][0] = true;

        std::array<int, 4> di{1, 0, -1, 0};
        std::array<int, 4> dj{0, -1, 0, 1};

        for (auto it = 0; it < 2 * n * m && !q.empty(); it++)
        {
            const auto [d, par, i, j] = *std::cbegin(q);
            q.erase(std::cbegin(q));                

            const auto add = par == 0 ? 1 : 2;

            for (auto pos = 0; pos < 4; pos++)
            {
                const auto ni = i + di[pos];
                const auto nj = j + dj[pos];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj][par ^ 1])
                {
                    const auto upd = std::max(moveTime[ni][nj], d) + add;

                    if (dist[ni][nj][par ^ 1] > upd)
                    {
                        dist[ni][nj][par ^ 1] = upd;
                        visited[ni][nj][par ^ 1] = true;
                        q.insert({upd, par ^ 1, ni, nj});
                    }
                }
            }
        }

        return std::min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    }
};
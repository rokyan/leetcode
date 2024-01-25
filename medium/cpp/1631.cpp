// https://leetcode.com/problems/path-with-minimum-effort/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int minimumEffortPath(std::vector<std::vector<int>>& heights)
    {
        const auto n = std::size(heights);
        const auto m = std::size(heights.front());

        std::vector<std::vector<int>> dst(n, std::vector<int>(m, inf));
        dst[0][0] = 0;

        std::priority_queue<std::tuple<int, int, int>> heap;
        heap.push(std::make_tuple(0, 0, 0));

        std::array<int, 4> dr{ 1, 0, -1, 0 };
        std::array<int, 4> dc{ 0, -1, 0, 1 };

        while (!heap.empty())
        {
            const auto [curd, r, c] = heap.top();
            heap.pop();

            for (auto idx = 0; idx < 4; idx++)
            {
                const auto nextr = r + dr[idx];
                const auto nextc = c + dc[idx];

                if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m &&
                    dst[nextr][nextc] > std::max(-curd, std::abs(heights[r][c] - heights[nextr][nextc])))
                {
                    dst[nextr][nextc] = std::max(-curd, std::abs(heights[r][c] - heights[nextr][nextc]));
                    heap.push(std::make_tuple(-dst[nextr][nextc], nextr, nextc));
                }
            }
        }

        return dst[n - 1][m - 1];
    }
};
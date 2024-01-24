// https://leetcode.com/problems/the-maze-ii/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int shortestDistance(std::vector<std::vector<int>>& maze,
        std::vector<int>& start, std::vector<int>& destination)
    {
        const auto n = std::size(maze);
        const auto m = std::size(maze.front());

        std::priority_queue<std::tuple<int, int, int>> heap;
        heap.push(std::make_tuple(0, start[0], start[1]));

        std::unordered_map<int, int> dst;
        const auto enc = [m](auto r, auto c) {
            return r * m + c;
        };

        for (auto r = 0; r < n; r++)
        {
            for (auto c = 0; c < m; c++)
            {
                dst[enc(r, c)] = inf;
            }
        }

        dst[enc(start[0], start[1])] = 0;

        std::array<int, 4> dr{ 1, 0, -1, 0 };
        std::array<int, 4> dc{ 0, -1, 0, 1 };

        while (!heap.empty())
        {
            auto [d, r, c] = heap.top();
            heap.pop();
            d *= -1;

            for (auto i = 0; i < 4; i++)
            {
                auto rr = r + dr[i];
                auto cc = c + dc[i];
                auto len = 0;

                while (rr >= 0 && rr < n && cc >= 0 && cc < m && !maze[rr][cc])
                {
                    len++;
                    rr += dr[i];
                    cc += dc[i];
                }

                rr -= dr[i];
                cc -= dc[i];

                if (dst[enc(rr, cc)] > d + len)
                {
                    dst[enc(rr, cc)] = d + len;
                    heap.push(std::make_tuple(-dst[enc(rr, cc)], rr, cc));
                }
            }
        }

        const auto ret = dst[enc(destination[0], destination[1])];
        return ret == inf ? -1 : ret;
    }
};
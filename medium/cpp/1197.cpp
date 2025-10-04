// https://leetcode.com/problems/minimum-knight-moves/description/

class Solution
{
public:
    int minKnightMoves(int x, int y)
    {
        if (x == 0 && y == 0)
        {
            return 0;
        }

        std::unordered_map<int, int> distance;
        distance[transform(0, 0)] = 0;

        std::queue<std::pair<int, int>> q;
        q.push({0, 0});

        std::array<int, 8> dr{2, 1, -1, -2, -2, -1, 1, 2};
        std::array<int, 8> dc{-1, -2, -2, -1, 1, 2, 2, 1};

        while (!q.empty())
        {
            const auto [r, c] = q.front();
            q.pop();

            const int curDistance = distance[transform(r, c)];

            for (auto d = 0; d < 8; d++)
            {
                const int nr = r + dr[d];
                const int nc = c + dc[d];

                if (nr < -300 || nr > 300 || nc < -300 || nc > 300 || std::abs(nr) + std::abs(nc) > 300)
                {
                    continue;
                }

                if (distance.count(transform(nr, nc)))
                {
                    continue;
                }

                if (nr == x && nc == y)
                {
                    return curDistance + 1;
                }

                distance[transform(nr, nc)] = curDistance + 1;
                q.push({nr, nc});
            }
        }

        return distance[transform(x, y)];
    }

private:
    int transform(int x, int y)
    {
        x += 300;
        y += 300;
        return x + 600 * y;
    }
};
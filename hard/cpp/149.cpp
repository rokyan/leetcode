// https://leetcode.com/problems/max-points-on-a-line/description/

class Solution
{
public:
    int maxPoints(const std::vector<std::vector<int>>& points)
    {
        const auto n = std::size(points);
        auto res = 1;

        for (auto i = 0; i + 1 < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                const auto a = points[i][1] - points[j][1];
                const auto b = points[j][0] - points[i][0];
                const auto c = points[i][0] * (points[j][1] - points[i][1]) +
                    points[i][1] * (points[i][0] - points[j][0]);

                auto cnt = 0;

                for (auto k = 0; k < n; k++)
                {
                    if (a * points[k][0] + b * points[k][1] + c == 0)
                    {
                        cnt++;
                    }
                }

                res = std::max(res, cnt);
            }
        }

        return res;
    }
};
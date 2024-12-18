// https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-i/description/

class Solution
{
public:
    int maxRectangleArea(std::vector<std::vector<int>>& points)
    {
        std::sort(std::begin(points), std::end(points), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
        });

        const auto n = std::size(points);

        auto res = -1;

        for (auto i = 0; i + 1 < n; i++)
        {
            if (points[i][0] == points[i + 1][0])
            {
                for (auto j = i + 2; j + 1 < n; j++)
                {
                    if (points[j][0] > points[i][0] &&
                        points[j][0] == points[j + 1][0] &&
                        points[j][1] == points[i][1] && points[j + 1][1] == points[i + 1][1])
                    {
                        auto valid = true;

                        for (auto k = i + 2; k < j; k++)
                        {
                            if (points[k][1] >= points[i][1] && points[k][1] <= points[i + 1][1])
                            {
                                valid = false;
                                break;
                            }
                        }

                        if (valid)
                        {
                            res = std::max(res,
                                (points[i + 1][1] - points[i][1]) * (points[j][0] - points[i][0]));
                        }
                    }
                }
            }
        }

        return res;
    }
};
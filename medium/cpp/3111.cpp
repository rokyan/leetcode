// https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/

class Solution
{
public:
    int minRectanglesToCoverPoints(const std::vector<std::vector<int>>& points, int w)
    {
        const auto n = std::size(points);

        std::vector<int> x(n);

        for (auto i = 0; i < n; i++)
        {
            x[i] = points[i][0];
        }

        std::sort(std::begin(x), std::end(x));

        auto last = x.front();
        auto cnt = 1;

        for (auto i = 1; i < n; i++)
        {
            if (x[i] - last > w)
            {
                last = x[i];
                cnt++;
            }
        }

        return cnt;
    }
};
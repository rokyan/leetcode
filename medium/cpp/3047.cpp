// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/

class Solution
{
public:
    long long largestSquareArea(
        const std::vector<std::vector<int>>& bottomLeft,
        const std::vector<std::vector<int>>& topRight)
    {
        auto res = 0;

        const auto n = std::size(bottomLeft);

        for (auto i = 0; i + 1 < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                const auto xiLeft = bottomLeft[i][0];
                const auto xiRight = topRight[i][0];
                const auto xjLeft = bottomLeft[j][0];
                const auto xjRight = topRight[j][0];
                const auto xLen = std::min(xiRight, xjRight) - std::max(xiLeft, xjLeft);

                if (xLen > 0)
                {
                    const auto yiBottom = bottomLeft[i][1];
                    const auto yiTop = topRight[i][1];
                    const auto yjBottom = bottomLeft[j][1];
                    const auto yjTop = topRight[j][1];
                    const auto yLen = std::min(yiTop, yjTop) - std::max(yiBottom, yjBottom);

                    if (yLen > 0)
                    {
                        res = std::max(res, std::min(xLen, yLen));
                    }
                }
            }
        }

        return 1LL * res * res;
    }
};
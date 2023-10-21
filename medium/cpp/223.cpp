// https://leetcode.com/problems/rectangle-area/description/

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        const auto xleft = std::max(ax1, bx1);
        const auto xright = std::min(ax2, bx2);

        const auto ylow = std::max(ay1, by1);
        const auto yhigh = std::min(ay2, by2);

        auto is = 0;

        if (xright >= xleft && yhigh >= ylow)
        {
            is = (xright - xleft) * (yhigh - ylow);
        }

        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - is;
    }
};
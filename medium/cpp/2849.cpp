// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        const auto d1 = std::abs(sx - fx) + 1;
        const auto d2 = std::abs(sy - fy) + 1;

        if (d1 == 1 && d2 == 1)
        {
            return t != 1;
        }

        const auto len1 = std::max(d1, d2) - 1;

        if (t < len1)
        {
            return false;
        }

        if ((len1 - t) % 2 == 0)
        {
            return true;
        }

        const auto len2 = len1 + 1;

        if ((len2 - t) % 2 == 0)
        {
            return true;
        }

        return false;
    }
};
https://leetcode.com/problems/construct-the-longest-new-string/description/

class Solution
{
public:
    int longestString(int x, int y, int z)
    {
        auto res = std::min(x, y);
        x -= res;
        y -= res;

        res *= 2;
        res += z;

        if (x > 0 || y > 0)
        {
            res++;
        }

        return 2 * res;
    }
};
// https://leetcode.com/problems/reverse-integer/description/

class Solution
{
private:
    static constexpr auto MAX = (1LL << 31) - 1;

public:
    int reverse(int x)
    {
        auto cp = 1LL * x;

        const auto negative = (cp < 0);

        if (negative)
        {
            cp = -cp;
        }

        auto res = 0LL;

        while (cp > 0)
        {
            res = 10 * res + cp % 10;
            cp /= 10;

            if (res > MAX)
            {
                return 0;
            }
        }

        if (negative)
        {
            res = -res;
        }

        return static_cast<int>(res);
    }
};
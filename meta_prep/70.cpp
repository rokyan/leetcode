class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }

        auto x = 1;
        auto y = 2;

        for (auto i = 3; i <= n; i++)
        {
            const auto z = x + y;
            x = y;
            y = z;
        }

        return y;
    }
};
// https://leetcode.com/problems/minimum-array-end/description/

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        auto res = 0LL;
        auto b = 0;
        n--;

        while (x || n)
        {
            if (x & 1)
            {
                res |= (1LL << b);
                x >>= 1;
                b++;
            }
            else
            {
                if (n & 1)
                {
                    res |= (1LL << b);
                }

                n >>= 1;
                x >>= 1;
                b++;
            }
        }

        return res;
    }
};
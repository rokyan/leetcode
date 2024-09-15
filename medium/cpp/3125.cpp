// https://leetcode.com/problems/maximum-number-that-makes-result-of-bitwise-and-zero/description/

class Solution
{
public:
    long long maxNumber(long long n)
    {
        auto res = 0LL;

        for (auto bit = 63; bit >= 0; bit--)
        {
            if (n & (1LL << bit))
            {
                for (auto next = bit - 1; next >= 0; next--)
                {
                    res |= (1LL << next);
                }

                break;
            }
        }

        return res;
    }
};
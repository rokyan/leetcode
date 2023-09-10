// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/

class Solution
{
public:
    int smallestValue(int n)
    {
        for (;;)
        {
            auto sum = 0;
            auto nn = n;

            for (auto num = 2; num * num <= n; num++)
            {
                while (n % num == 0)
                {
                    sum += num;
                    n /= num;
                }
            }

            if (n > 1)
            {
                sum += n;
            }

            n = sum;

            if (n == nn)
            {
                break;
            }
        }

        return n;
    }
};
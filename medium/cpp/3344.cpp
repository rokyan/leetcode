// https://leetcode.com/problems/maximum-sized-array/description/

class Solution
{
public:
    int maxSizedArray(long long s)
    {
        if (s == 0)
        {
            return 1;
        }

        auto lo = 0LL;
        auto hi = 0LL;

	// magic
        while (hi * hi * hi * hi <= s)
        {
            hi++;
        }

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo + 1) / 2;
            auto sum = 0LL;

            auto t = 0LL;

            for (auto j = 0; j < mid; j++)
            {
                for (auto k = 0; k < mid; k++)
                {
                    t += j | k;
                }
            }

            for (auto i = 0; i < mid && sum <= s; i++)
            {
                sum += 1LL * i * t;
            }

            if (sum <= s)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
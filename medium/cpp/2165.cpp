// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/

class Solution
{
public:
    long long smallestNumber(long long num)
    {
        std::array<int, 10> cnt { 0 };

        auto neg = false;

        if (num < 0)
        {
            num *= -1;
            neg = true;
        }

        while (num > 0)
        {
            cnt[num % 10]++;
            num /= 10;
        }

        auto res = 0LL;

        if (neg)
        {
            for (auto i = 9; i >= 1; i--)
            {
                if (cnt[i] > 0)
                {
                    cnt[i]--;
                    res = i;
                    break;
                }
            }

            for (auto i = 9; i >= 0; i--)
            {
                while (cnt[i] > 0)
                {
                    res = 10 * res + i;
                    cnt[i]--;
                }
            }

            res *= -1;
        }
        else
        {
            for (auto i = 1; i <= 9; i++)
            {
                if (cnt[i] > 0)
                {
                    cnt[i]--;
                    res = i;
                    break;
                }
            }

            for (auto i = 0; i <= 9; i++)
            {
                while (cnt[i] > 0)
                {
                    res = 10 * res + i;
                    cnt[i]--;
                }
            }
        }

        return res;
    }
};
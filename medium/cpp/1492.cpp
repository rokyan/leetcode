// https://leetcode.com/problems/the-kth-factor-of-n/description/

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        auto tot = 0;

        for (auto i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                tot += 2;

                if (i == n / i)
                {
                    tot--;
                }
            }
        }

        if (k > tot)
        {
            return -1;
        }

        if (k <= (tot + 1) / 2)
        {
            for (auto i = 1; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    k--;
                }

                if (k == 0)
                {
                    return i;
                }
            }
        }
        else
        {
            k -= (tot + 1) / 2;

            auto i = 1;

            while ((i + 1) * (i + 1) < n)
            {
                i++;
            }

            std::cout << k << " " << i << std::endl;

            for (auto j = i; j >= 0; j--)
            {
                if (n % j == 0)
                {
                    k--;
                }

                if (k == 0)
                {
                    return n / j;
                }
            }
        }

        return -1;
    }
};
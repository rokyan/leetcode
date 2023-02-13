// https://leetcode.com/problems/closest-prime-numbers-in-range/description/

class Solution
{
public:
    std::vector<int> closestPrimes(int left, int right)
    {
        std::vector<char> is_prime(right + 1, true);
        is_prime[1] = false;

        for (auto i = 2; i * i <= right; i++)
        {
            if (is_prime[i])
            {
                for (auto j = i * i; j <= right; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }

        std::vector<int> res { -1, -1 };

        auto diff = -1;
        auto last = -1;

        for (auto i = left; i <= right; i++)
        {
            if (is_prime[i])
            {
                if (last == -1)
                {
                    last = i;
                }
                else
                {
                    if (diff == -1 || diff > i - last)
                    {
                        diff = i - last;
                        res = { last, i };
                    }

                    last = i;
                }
            }
        }

        return res;
    }
};
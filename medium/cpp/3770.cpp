// https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/description/

class Solution
{
public:
    int largestPrime(int n)
    {
        if (n <= 1)
        {
            return 0;
        }

        std::vector<char> isPrime(n + 1, true);

        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int res = 2;
        int s = 0;

        for (int val = 2; val <= n; val++)
        {
            if (isPrime[val])
            {
                s += val;
            }

            if (s > n)
            {
                break;
            }

            if (isPrime[s])
            {
                res = s;
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/description/

class Solution
{
public:
    int sumOfPrimesInRange(int n)
    {
        const int nrev = rev(n);
        const int lo = std::min(nrev, n);
        const int hi = std::max(nrev, n);

        int res = 0;

        for (int x = lo; x <= hi; x++)
        {
            res += isPrime(x) ? x : 0;
        }

        return res;
    }

private:
    int rev(int n)
    {
        int res = 0;

        while (n)
        {
            res = 10 * res + n % 10;
            n /= 10;
        }

        return res;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }

        for (int d = 2; d * d <= n; d++)
        {
            if (n % d == 0)
            {
                return false;
            }
        }

        return true;
    }
};
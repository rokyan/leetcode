// https://leetcode.com/problems/sum-of-largest-prime-substrings/description/

class Solution
{
public:
    long long sumOfLargestPrimes(const std::string& s)
    {
        std::set<long long> primes;

        for (auto i = 0; i < std::size(s); i++)
        {
            for (auto j = i + 1; j <= std::size(s); j++)
            {
                const auto val = toLong(s, i, j);

                if (isPrime(val))
                {
                    primes.insert(val);

                    if (std::size(primes) > 3)
                    {
                        primes.erase(std::begin(primes));
                    }
                }
            }
        }

        auto res = 0LL;

        for (auto e : primes)
        {
            res += e;
        }

        return res;
    }

private:
    long long toLong(const std::string& s, int l, int r)
    {
        long long res = 0;

        while (l < r)
        {
            res = 10 * res + (s[l++] - '0');
        }

        return res;
    }

    bool isPrime(long long val)
    {
        if (val <= 1)
        {
            return false;
        }

        for (auto i = 2LL; i * i <= val; i++)
        {
            if (val % i == 0)
            {
                return false;
            }
        }

        return true;
    }
};
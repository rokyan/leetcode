// https://leetcode.com/problems/prime-pairs-with-target-sum/description/

class Solution
{
public:
    std::vector<std::vector<int>> findPrimePairs(int n)
    {
        std::vector<char> sieve(n + 1, true);
        
        for (auto i = 2; i * i <= n; i++)
        {
            if (sieve[i])
            {
                for (auto j = i * i; j <= n; j += i)
                {
                    sieve[j] = false;
                }
            }
        }

        std::vector<int> primes;
        primes.reserve(n / 2);

        for (auto i = 2; i <= n; i++)
        {
            if (sieve[i])
            {
                primes.push_back(i);
            }
        }

        std::vector<std::vector<int>> res;

        for (auto i = 0, j = static_cast<int>(std::size(primes)) - 1; i <= j; i++)
        {
            while (i <= j && primes[i] + primes[j] > n)
            {
                j--;
            }

            if (i <= j && primes[i] + primes[j] == n)
            {
                res.push_back({ primes[i], primes[j] });
            }
        }

        return res;
    }
};
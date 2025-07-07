// https://leetcode.com/problems/minimum-number-of-primes-to-sum-to-target/description/

class Solution
{
public:
    int minNumberOfPrimes(int n, int m)
    {
        std::vector<int> primes;
        primes.reserve(n / 2);

        for (auto num = 2; num <= n && std::size(primes) < m; num++)
        {
            auto prime = true;

            for (auto div = 2; div * div <= num; div++)
            {
                if (num % div == 0)
                {
                    prime = false;
                    break;
                }
            }

            if (prime)
            {
                primes.push_back(num);
            }
        }

        const auto inf = 1000'000'000;

        std::vector<int> dp(n + 1, inf);

        for (auto num = 2; num <= n; num++)
        {
            for (const auto p : primes)
            {
                if (num == p)
                {
                    dp[num] = 1;
                    break;
                }

                if (num > p)
                {
                    dp[num] = std::min(dp[num], dp[num - p] + 1);
                }
            }
        }

        return dp.back() == inf ? -1 : dp.back();
    }
};
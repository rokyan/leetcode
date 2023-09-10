// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/

class Solution
{
public:
    int distinctPrimeFactors(std::vector<int>& nums)
    {
        const auto n = *std::max_element(std::begin(nums), std::end(nums));

        std::vector<char> isPrime(n + 1, true);
        auto res = 0;

        for (auto i = 2; i <= n; i++)
        {
            if (isPrime[i])
            {
                for (auto num : nums)
                {
                    if (num % i == 0)
                    {
                        res++;
                        break;
                    }
                }

                for (auto j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        return res;
    }
};
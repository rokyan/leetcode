// https://leetcode.com/problems/minimum-operations-to-transform-array-into-alternating-prime/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums)
    {
        const auto primes{genPrimes()};

        const int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            const auto it = std::lower_bound(primes.begin(), primes.end(), nums[i]);

            if (i % 2 == 0)
            {
                if (*it != nums[i])
                {
                    const int next = *it;
                    res += next - nums[i];
                }
            }
            else
            {
                if (*it == nums[i])
                {
                    const int next = nums[i] <= 3 ? 4 : nums[i] + 1;
                    res += next - nums[i];
                }
            }
        }

        return res;
    }

private:
    std::vector<int> genPrimes()
    {
        const int maxVal = 100100;

        std::vector<int> primes;

        std::vector<char> isPrime(maxVal, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i < maxVal; i++)
        {
            if (isPrime[i])
            {
                primes.push_back(i);

                for (long long j = 1LL * i * i; j < maxVal; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        return primes;
    }
};
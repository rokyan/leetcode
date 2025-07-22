// https://leetcode.com/problems/count-prime-gap-balanced-subarrays/description/

class Solution
{
public:
    int primeSubarray(const std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::multiset<int> primes;

        std::array<int, 2> idxs{-1, -1};

        auto res = 0;

        for (auto l = 0, r = 0; r < n; r++)
        {
            if (isPrime(nums[r]))
            {
                primes.insert(nums[r]);
                idxs[0] = idxs[1];
                idxs[1] = r;
            }

            while (!primes.empty() &&
                *std::crbegin(primes) - *std::cbegin(primes) > k)
            {
                if (const auto it = primes.find(nums[l++]); it != std::cend(primes))
                {
                    primes.erase(it);
                }
            }

            if (std::size(primes) >= 2)
            {
                if (idxs[0] >= l)
                {
                    res += idxs[0] - l + 1;
                }
            } 
        }

        return res;
    }

private:
    bool isPrime(int value)
    {
        if (value < 2)
        {
            return false;
        }

        for (auto div = 2; div * div <= value; div++)
        {
            if (value % div == 0)
            {
                return false;
            }
        }

        return true;
    }
};
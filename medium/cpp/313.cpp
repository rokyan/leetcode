// https://leetcode.com/problems/super-ugly-number/description/

class Solution
{
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes)
    {
        std::vector<int> idxs(std::size(primes));

        std::vector<int> nums(n);
        nums[0] = 1;

        for (auto i = 1; i < n; i++)
        {
            auto next = 1LL * nums[idxs[0]] * primes[0];

            for (auto j = 1; j < std::size(primes); j++)
            {
                next = std::min(next, 1LL * nums[idxs[j]] * primes[j]);
            }

            nums[i] = next;

            for (auto j = 0; j < std::size(primes); j++)
            {
                if (next == 1LL * nums[idxs[j]] * primes[j])
                {
                    idxs[j]++;
                }
            }
        }

        return nums.back();
    }
};
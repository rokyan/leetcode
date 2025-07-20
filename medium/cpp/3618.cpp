// https://leetcode.com/problems/split-array-by-prime-indices/description/

class Solution
{
public:
    long long splitArray(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        if (n == 1)
        {
            return nums[0];
        }

        std::vector<char> isPrime(n, 1);
        isPrime[0] = isPrime[1] = false;

        for (auto i = 2; i * i < n; i++)
        {
            for (auto j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            if (isPrime[i])
            {
                res += nums[i];
            }
            else
            {
                res -= nums[i];
            }
        }

        return std::abs(res);
    }
};
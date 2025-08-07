// https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int minMaxSums(std::vector<int>& nums, int k)
    {
        const int n = std::size(nums);

        precalcFact(n);

        auto res = 0;

        std::ranges::sort(nums);

        for (auto i = 0; i < n; i++)
        {           
            const auto rem = n - 1 - i;

            for (auto j = 0; j <= std::min(rem, k - 1); j++)
            {
                res += 1LL * calcCNK(rem, j) * nums[i] % mod;
                res %= mod;
            }
        }

        for (auto i = n - 1; i >= 0; i--)
        {
            const auto rem = i;

            for (auto j = 0; j <= std::min(rem, k - 1); j++)
            {
                res += 1LL * calcCNK(rem, j) * nums[i] % mod;
                res %= mod;
            }
        }

        return res;
    }

private:
    void precalcFact(int n)
    {
        fact.resize(n + 1);
        fact[0] = 1;

        for (auto i = 1; i <= n; i++)
        {
            fact[i] = 1LL * fact[i - 1] * i % mod;
        }
    }

    int calcCNK(int n, int k)
    {
        auto res = fact[n];
        res = 1LL * res * inv(fact[k]) % mod;
        res = 1LL * res * inv(fact[n - k]) % mod;
        return res;
    }

    int inv(int n)
    {
        const auto it = invCache.find(n);

        if (it != std::end(invCache))
        {
            return it->second;
        }

        invCache[n] = pow(n, mod - 2);
        return invCache[n];
    }

    int pow(int n, int p)
    {
        if (p == 0)
        {
            return 1;
        }

        if (p % 2 == 1)
        {
            return 1LL * n * pow(n, p - 1) % mod;
        }

        const auto temp = pow(n, p / 2);
        return 1LL * temp * temp % mod;
    }

private:
    std::vector<int> fact;
    std::unordered_map<int, int> invCache;
};
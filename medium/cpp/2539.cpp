// https://leetcode.com/problems/count-the-number-of-good-subsequences/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int countGoodSubsequences(std::string s)
    {
        const auto n = std::size(s);

        std::vector<int> f(n + 1);
        f[0] = 1;

        for (auto i = 1; i <= n; i++)
        {
            f[i] = 1LL * i * f[i - 1] % mod;
        }

        std::vector<int> cnt(26);
        auto times = 0;

        for (auto i = 0; i < n; i++)
        {
            times = std::max(times, ++cnt[s[i] - 'a']);
        }

        auto res = 0;

        for (auto i = 1; i <= times; i++)
        {
            auto cur = 1;

            for (auto j = 0; j < 26; j++)
            {
                if (cnt[j] >= i)
                {
                    cur = (1LL * f[cnt[j]] * inv(f[i]) % mod * inv(f[cnt[j] - i]) % mod + 1) * cur % mod; 
                }
            }

            res += cur - 1;
            res %= mod;
        }

        return res;
    }

private:
    int bin_pow(int b, int p)
    {
        if (p == 1)
        {
            return b;
        }

        if (p % 2 == 1)
        {
            return 1LL * b * bin_pow(b, p - 1) % mod;
        }
        else
        {
            const auto temp = bin_pow(b, p / 2) % mod;
            return 1LL * temp * temp % mod;
        }
    }

    int inv(int x)
    {
        return bin_pow(x, mod - 2);
    }
};
// https://leetcode.com/problems/count-good-numbers/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countGoodNumbers(long long n)
    {
        auto res = 1;

        res = 1LL * res * bin_pow(5, n / 2 + (n % 2 != 0)) % mod;
        res = 1LL * res * bin_pow(4, n / 2) % mod;

        return res;
    }

private:
    int bin_pow(int x, long long p)
    {
        if (p == 0)
        {
            return 1;
        }

        if (p & 1)
        {
            return 1LL * x * bin_pow(x, p - 1) % mod;
        }

        const auto im = bin_pow(x, p / 2);

        return 1LL * im * im % mod;
    }
};
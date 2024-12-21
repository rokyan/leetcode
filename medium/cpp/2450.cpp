// https://leetcode.com/problems/number-of-distinct-binary-strings-after-applying-operations/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countDistinctStrings(const std::string& s, int k)
    {
        const auto n = std::size(s);

        return bin_pow(n - k + 1);
    }

private:
    int bin_pow(int p)
    {
        if (p == 1)
        {
            return 2;
        }

        if (p & 1)
        {
            return 1LL * 2 * bin_pow(p - 1) % mod;
        }

        const auto t = bin_pow(p / 2);
        return 1LL * t * t % mod;
    }
};
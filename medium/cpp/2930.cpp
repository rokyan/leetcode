// https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int stringCount(int n)
    {
        if (n < 4)
        {
            return 0;
        }

        const auto temp = pow(26, n)
            - 2 * pow(25, n)
            - (pow(25, n) + n * pow(25, n - 1))
            + (pow(24, n) + n * pow(24, n - 1))
            + pow(24, n)
            + (pow(24, n) + n * pow(24, n - 1))
            - (pow(23, n) + n * pow(23, n - 1));
        
        return (temp % mod + mod) % mod;
    }

private:
    long long pow(long long x, int n)
    {
        if (n == 0)
        {
            return 1;
        }

        if (n % 2 == 1)
        {
            return x * pow(x, n - 1) % mod;
        }
        else
        {
            const auto temp = pow(x, n / 2);
            return temp * temp % mod;
        }
    }
};
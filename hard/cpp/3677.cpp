// https://leetcode.com/problems/count-binary-palindromic-numbers/description/

class Solution
{
public:
    int countBinaryPalindromes(long long n)
    {
        if (n <= 1)
        {
            return n + 1;
        }

        const std::vector<char> bits(toBits(n));
        const int len = bits.size();
        int total = 0;

        for (int i = 1; i < len; i++)
        {
            if (i == 1)
            {
                total += 2;
            }
            else
            {
                total += 1 << ((i - 1) / 2);
            }
        }

        long long pref = 0LL;

        for (int i = 0; i < (len + 1) / 2; i++)
        {
            pref = (pref << 1) | bits[i];
        }

        long long small = 1 << ((len - 1) / 2);

        if (pref >= small)
        {
            total += pref - small;

            std::vector<char> reflected;

            for (int i = 0; i < (len + 1) / 2; i++)
            {
                reflected.push_back(bits[i]);
            }

            for (int i = (len - 2) / 2; i >= 0; i--)
            {
                reflected.push_back(bits[i]);
            }

            total += reflected <= bits;
        }

        return total;
    }

private:
    std::vector<char> toBits(long long n)
    {
        if (n == 0)
        {
            return {0};
        }

        std::vector<char> bits;
        bits.reserve(64);

        while (n)
        {
            bits.push_back(n % 2);
            n /= 2;
        }

        std::ranges::reverse(bits);

        return bits;
    }
};
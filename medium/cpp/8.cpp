// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution
{
public:
    int myAtoi(const std::string& s)
    {
        const auto n = std::size(s);

        auto res = 0LL;
        auto mult = 1;
        auto pos = 0;

        while (pos < n && s[pos] == ' ')
        {
            pos++;
        }

        if (pos == n)
        {
            return 0;
        }

        if (s[pos] == '-')
        {
            mult *= -1;
            pos++;
        }
        else if (s[pos] == '+')
        {
            pos++;
        }

        while (pos < n && s[pos] == '0')
        {
            pos++;
        }

        while (pos < n && s[pos] >= '0' && s[pos] <= '9')
        {
            res = 10 * res + (s[pos] - '0');

            if (res * mult <= -(1LL << 31))
            {
                return -(1LL << 31);
            }

            if (res * mult >= (1LL << 31) - 1)
            {
                return (1LL << 31) - 1;
            }

            pos++;
        }

        return res * mult;
    }
};
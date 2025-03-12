class Solution
{
public:
    int myAtoi(const std::string& s)
    {
        auto pos = 0;
        const auto n = std::size(s);

        while (pos < n && s[pos] == ' ')
        {
            pos++;
        }

        auto neg = false;

        if (pos < n)
        {
            if (s[pos] == '-')
            {
                neg = true;
                pos++;
            }
            else if (s[pos] == '+')
            {
                neg = false;
                pos++;
            }
        }

        while (pos < n && s[pos] == '0')
        {
            pos++;
        }

        auto res = 0LL;
        const auto b = 1LL << 31;

        while (pos < n && std::isdigit(s[pos]))
        {
            const auto d = s[pos++] - '0';
            res = 10 * res + d;

            if (res * (neg ? -1 : 1) < -b)
            {
                res = -b;
                break;
            }

            if (res * (neg ? -1 : 1) > b - 1)
            {
                res = b - 1;
                break;
            }
        }

        return res * (neg ? -1 : 1);
    }
};
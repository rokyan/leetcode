// https://leetcode.com/problems/valid-number/description/

class Solution
{
public:
    bool isNumber(std::string s)
    {
        if (auto pos = s.find('e'); pos != std::string::npos)
        {
            return (is_decimal(s.substr(0, pos)) || is_integer(s.substr(0, pos))) && is_integer(s.substr(pos + 1));
        }

        if (auto pos = s.find('E'); pos != std::string::npos)
        {
            return (is_decimal(s.substr(0, pos)) || is_integer(s.substr(0, pos))) && is_integer(s.substr(pos + 1));
        }

        return is_decimal(s) || is_integer(s);
    }

private:
    bool is_decimal(const std::string& s)
    {
        if (s.empty())
        {
            return false;
        }

        auto rem = s.front() == '+' || s.front() == '-' ? s.substr(1) : s;
        auto pos = rem.find('.');

        if (pos == std::string::npos)
        {
            return false;
        }

        auto pref = rem.substr(0, pos);
        auto suff = rem.substr(pos + 1);

        if (pref.empty() && suff.empty())
        {
            return false;
        }

        return all_digits(pref) && suff.empty() ||
            all_digits(pref) && all_digits(suff) ||
            pref.empty() && all_digits(suff);
    }

    bool is_integer(const std::string& s)
    {
        if (s.empty())
        {
            return false;
        }

        auto rem = s.front() == '+' || s.front() == '-' ? s.substr(1) : s;

        if (rem.empty())
        {
            return false;
        }

        return all_digits(rem);
    }

    bool all_digits(const std::string& s)
    {
        return std::all_of(std::begin(s), std::end(s), [](char c) {
            return c >= '0' && c <= '9';
        });
    }
};
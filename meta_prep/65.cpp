class Solution
{
public:
    bool isNumber(const std::string& s)
    {
        std::string_view num{s};
        const auto exp_pos = find_exp(s);

        if (exp_pos != -1)
        {
            const auto base = num.substr(0, exp_pos);
            const auto exp = num.substr(exp_pos + 1);

            return (is_integer(base) || is_decimal(base)) && is_integer(exp);
        }

        return is_integer(num) || is_decimal(num);
    }

private:
    int find_exp(const std::string_view& num)
    {
        const auto it = std::find_if(std::cbegin(num), std::cend(num), [](auto d) {
            return d == 'E' || d == 'e';
        });

        return it == std::cend(num) ? -1 : std::distance(std::cbegin(num), it);
    }
    bool is_integer(std::string_view num)
    {
        if (has_sign(num))
        {
            num = num.substr(1);
        }

        if (num.empty())
        {
            return false;
        }

        return std::all_of(std::cbegin(num), std::cend(num), [](auto d) {
            return std::isdigit(d);
        });
    }

    bool is_decimal(std::string_view num)
    {
        if (has_sign(num))
        {
            num = num.substr(1);
        }

        if (num.empty())
        {
            return false;
        }

        auto dots = 0;
        auto digits = 0;

        for (auto d : num)
        {
            if (!std::isdigit(d))
            {
                if (d == '.')
                {
                    if (dots++ == 1)
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                digits++;
            }
        }

        return digits > 0;
    }

    bool has_sign(const std::string_view& num)
    {
        return !num.empty() && (num[0] == '+' || num[0] == '-');
    }
};
// https://leetcode.com/problems/apply-discount-to-prices/description/

class Solution
{
public:
    std::string discountPrices(std::string sentence, int discount)
    {
        std::istringstream is(sentence);
        std::string token;

        std::ostringstream os;
        os << std::fixed;
        os << std::setprecision(2);

        auto first = true;

        while (is >> token)
        {
            if (!first)
            {
                os << " ";
            }

            first = false;

            if (is_price(token))
            {
                const auto adjusted = std::stod(token.substr(1)) * (100.0 - discount) / 100.0;
                os << "$" << adjusted;
            }
            else
            {
                os << token;
            }
        }

        return os.str();
    }

private:
    bool is_price(const std::string& s)
    {
        return std::size(s) > 1 &&
            s[0] == '$' &&
            std::all_of(std::begin(s) + 1, std::end(s), [](char c) { return std::isdigit(c); });
    }
};
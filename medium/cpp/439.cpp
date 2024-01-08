// https://leetcode.com/problems/ternary-expression-parser/description/

class Solution
{
public:
    std::string parseTernary(std::string expression)
    {
        return eval(expression);
    }

private:
    std::string eval(const std::string& exp)
    {
        const auto p = exp.find('?');

        if (p == std::string::npos)
        {
            return exp;
        }

        auto c = 0;

        for (auto i = p + 1; i < std::size(exp); i++)
        {
            if (exp[i] == ':')
            {
                if (c == 0)
                {
                    return exp[0] == 'T' ? eval(exp.substr(p + 1, i - p - 1)) : eval(exp.substr(i + 1)); 
                }
                else
                {
                    c--;
                }
            }
            else if (exp[i] == '?')
            {
                c++;
            }
        }

        return "";
    }
};
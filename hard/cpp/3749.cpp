https://leetcode.com/problems/evaluate-valid-expressions/description/

class Solution
{
public:
    long long evaluateExpression(const std::string& expression)
    {
        std::size_t pos = 0;
        return eval(expression, pos);
    }

private:
    long long eval(std::string_view expression, std::size_t& pos)
    {
        if (std::isalpha(expression[pos]))
        {
            const char op = expression[pos];
            pos += 4;

            const long long left = eval(expression, pos);
            pos++;
            const long long right = eval(expression, pos);
            pos++;

            switch (op)
            {
                case 'a':
                    return left + right;
                case 's':
                    return left - right;
                case 'm':
                    return left * right;
                default:
                    return left / right;
            }
        }

        bool negative = false;

        if (expression[pos] == '-')
        {
            negative = true;
            pos++;
        }

        long long num = 0LL;

        while (pos < expression.size() && std::isdigit(expression[pos]))
        {
            num = 10 * num + (expression[pos++] - '0');
        }

        return negative ? -num : num;
    }
};
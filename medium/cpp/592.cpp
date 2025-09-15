// https://leetcode.com/problems/fraction-addition-and-subtraction/description/

class Solution
{
public:
    std::string fractionAddition(const std::string& expression)
    {
        std::pair<int, int> acc{0, 1};

        for (auto i = 0; i < std::size(expression); )
        {
            auto sign = 1;

            if (expression[i] == '+')
            {
                i++;
            }
            else if (expression[i] == '-')
            {
                sign = -1;
                i++;
            }

            auto x = 0;

            while (expression[i] != '/')
            {
                x = 10 * x + expression[i++] - '0';
            }

            x *= sign;

            i++;

            auto y = 0;

            while (i < std::size(expression) && expression[i] != '+' && expression[i] != '-')
            {
                y = 10 * y + expression[i++] - '0';
            }

            // std::cout << x << " " << y << std::endl;

            acc = add(acc, {x, y});
        }

        return std::to_string(acc.first) + "/" + std::to_string(acc.second);
    }

private:
    std::pair<int, int> add(const std::pair<int, int>& left, const std::pair<int, int>& right)
    {
        const auto leftUpd = std::make_pair(left.first * right.second, left.second * right.second);
        const auto rightUpd = std::make_pair(right.first * left.second, right.second * left.second);
        const auto sum = std::make_pair(leftUpd.first + rightUpd.first, left.second * right.second);
        const auto gcdVal = gcd(std::abs(sum.first), std::abs(sum.second));
        return {sum.first / gcdVal, sum.second / gcdVal};
    }

    int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }
};
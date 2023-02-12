// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/description/

class Solution
{
public:
    std::string minimizeResult(std::string expression)
    {
        const auto plus_pos = expression.find('+');

        const auto left = expression.substr(0, plus_pos);
        const auto right = expression.substr(plus_pos + 1);

        auto val = -1;
        std::string res;

        for (auto i = 0; i < std::size(left); i++)
        {
            const auto a = (i == 0) ? 1 : std::stoi(left.substr(0, i));
            const auto b = std::stoi(left.substr(i));

            for (auto j = 0; j < std::size(right); j++)
            {
                const auto c = std::stoi(right.substr(0, j + 1));
                const auto d = j + 1 == std::size(right) ? 1 : std::stoi(right.substr(j + 1));

                if (val == -1 || a * (b + c) * d < val)
                {
                    val = a * (b + c) * d;

                    res = expression;
                    res.insert(i, 1, '(');
                    res.insert(plus_pos + 2 + j + 1, 1, ')');
                }
            }
        }

        return res;
    }
};
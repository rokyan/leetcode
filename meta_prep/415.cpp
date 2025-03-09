class Solution
{
public:
    std::string addStrings(const std::string& num1, const std::string& num2)
    {
        std::string res;
        int carry = 0;

        for (int i = std::size(num1) - 1, j = std::size(num2) - 1; i >= 0 || j >= 0; i--, j--)
        {
            const auto s = carry +
                (i >= 0 ? num1[i] - '0' : 0) +
                (j >= 0 ? num2[j] - '0' : 0);

            res.push_back(s % 10 + '0');
            carry = s / 10;
        }

        if (carry > 0)
        {
            res.push_back(carry + '0');
        }

        std::reverse(std::begin(res), std::end(res));

        return res;
    }
};
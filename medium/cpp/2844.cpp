// https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/

class Solution
{
public:
    int minimumOperations(std::string num)
    {
        return std::min(count(num, 0, 0), std::min(count(num, 5, 2), std::min(count(num, 0, 5), count(num, 5, 7))));
    }

private:
    int count(const std::string& num, int a, int b)
    {
        auto matches = 0;
        auto pos = 0;

        for (auto i = static_cast<int>(std::size(num)) - 1; i >= 0; i--)
        {
            if (matches == 0 && num[i] - '0' == a)
            {
                matches = 1;
            }
            else if (matches == 1 && num[i] - '0' == b)
            {
                matches = 2;
                pos = i;
                break;
            }
        }

        // std::cout << a << " " << b << " " << matches << " " << pos << std::endl;

        const auto hz = std::find(std::begin(num), std::end(num), '0') != std::end(num);

        if (matches < 2)
        {
            return std::size(num) - hz;
        }

        return std::size(num) - pos - 2;
    }
};
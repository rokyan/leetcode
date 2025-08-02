// https://leetcode.com/problems/smallest-number-with-given-digit-product/description/

class Solution
{
public:
    string smallestNumber(long long n)
    {
        if (n == 1)
        {
            return "1";
        }

        std::string digits;

        for (auto d = 9; d > 1; d--)
        {
            while (n % d == 0)
            {
                n /= d;
                digits.push_back(d + '0');
            }
        }

        if (n > 1)
        {
            return "-1";
        }

        std::ranges::reverse(digits);
        return digits;
    }
};
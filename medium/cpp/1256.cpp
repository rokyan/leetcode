// https://leetcode.com/problems/encode-number/description/

class Solution
{
public:
    std::string encode(int num)
    {
        if (num == 0)
        {
            return std::string{};
        }

        auto p = 2;
        auto len = 1;

        while (p < num)
        {
            num -= p;
            p *= 2;
            len++;
        }

        num--;

        auto res = std::string{};

        while (num > 0)
        {
            res.push_back('0' + (num % 2));
            num /= 2;
            len--;
        }


        while (len--)
        {
            res.push_back('0');
        }

        std::reverse(std::begin(res), std::end(res));

        return res;
    }
};
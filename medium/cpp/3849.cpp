// https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/description/

class Solution
{
public:
    std::string maximumXor(const std::string& s, const std::string& t)
    {
        int zero = 0;
        int one = 0;

        for (char c : t)
        {
            if (c == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }

        std::string res;
        res.reserve(s.size());

        for (char c : s)
        {
            if (c == '0' && one > 0)
            {
                res.push_back('1');
                one--;
            }
            else if (c == '1' && zero > 0)
            {
                res.push_back('1');
                zero--;
            }
            else
            {
                res.push_back('0');
            }
        }

        return res;
    }
};
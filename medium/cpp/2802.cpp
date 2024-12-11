// https://leetcode.com/problems/find-the-k-th-lucky-number/description/

class Solution
{
public:
    std::string kthLuckyNumber(int k)
    {
        auto len = 1;
        auto p = 2;
        auto tot = p;
        auto prev = 0;

        while (tot < k)
        {
            p *= 2;
            prev = tot;
            tot += p;
            len++;
        }

        std::string res;
        res.reserve(len);

        k -= prev;
        p /= 2;

        std::cout << k << " " << p << std::endl;

        for (auto i = len - 1; i >= 0; i--, p /= 2)
        {
            if (p >= k)
            {
                res.push_back('4');
             }
            else
            {
                res.push_back('7');
                k -= p;
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/find-palindrome-with-fixed-length/description/

class Solution
{
public:
    std::vector<long long> kthPalindrome(std::vector<int>& queries, int intLength)
    {
        auto half = (intLength - 1) / 2;

        auto base = 1LL;

        for (auto _ = 0; _ < half; _++)
        {
            base *= 10;
        }

        std::vector<long long> res;
        res.reserve(std::size(queries));

        for (auto query : queries)
        {
            if (query > base * 10 - base)
            {
                res.push_back(-1);
                continue;
            }
            
            auto cur = base + query - 1;
            auto p = cur;

            if (intLength % 2)
            {
                cur /= 10;
            }

            while (cur)
            {
                p = 10 * p + cur % 10;
                cur /= 10;
            }

            res.push_back(p);
        }

        return res;
    }
};
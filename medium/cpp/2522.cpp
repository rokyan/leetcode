// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/

class Solution
{
public:
    int minimumPartition(std::string s, int k)
    {
        auto res = 0;
        auto acc = 0LL;

        for (auto i = 0; i < std::size(s); i++)
        {
            const auto d = s[i] - '0';

            if (d > k)
            {
                return -1;
            }

            if (acc * 10 + d <= k)
            {
                acc *= 10;
                acc += d;
            }
            else
            {
                res++;
                acc = d;
            }
        }

        return res + 1;
    }
};
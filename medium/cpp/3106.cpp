// https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/description/

class Solution
{
public:
    std::string getSmallestString(const std::string& s, int k)
    {
        const auto n = std::size(s);
        std::string res{ s };

        for (auto i = 0; i < n; i++)
        {
            const auto d = std::min(s[i] - 'a', 'z' - s[i] + 1);

            if (k >= d)
            {
                k -= d;
                res[i] = 'a';
            }
            else if (k > 0)
            {
                res[i] = s[i] - k;
                k = 0;
            }
            else
            {
                break;
            }
        }

        return res;
    }
};
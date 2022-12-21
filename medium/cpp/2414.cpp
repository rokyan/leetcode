// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/

class Solution
{
public:
    int longestContinuousSubstring(std::string s)
    {
        auto res = 0;
        auto len = 1;

        for (auto pos = 1; pos < std::size(s); pos++)
        {
            if (s[pos] == s[pos - 1] + 1)
            {
                len++;
            }
            else
            {
                res = std::max(res, len);
                len = 1;
            }
        }

        return std::max(res, len);
    }
};
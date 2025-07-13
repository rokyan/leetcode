// https://leetcode.com/problems/longest-common-prefix-after-at-most-one-removal/description/

class Solution
{
public:
    int longestCommonPrefix(const std::string& s, const std::string& t)
    {
        const auto n = std::size(s);
        const auto m = std::size(t);

        auto p = 0;

        while (p < n && p < m && s[p] == t[p])
        {
            p++;
        }

        if (p == n || p == m)
        {
            return p;
        }

        auto res = p;

        while (p + 1 < n && p < m && s[p + 1] == t[p])
        {
            p++;
            res++;
        }

        return res;
    }
};
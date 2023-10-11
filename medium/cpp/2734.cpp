// https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/

class Solution
{
public:
    std::string smallestString(std::string s)
    {
        auto pos = 0;

        while (pos < std::size(s) && s[pos] == 'a')
        {
            pos++;
        }

        if (pos == std::size(s))
        {
            s.back() = 'z';
            return s;
        }

        while (pos < std::size(s) && s[pos] != 'a')
        {
            s[pos] = 'a' + (s[pos] - 'a' - 1 + 26) % 26;
            pos++;
        }

        return s;
    }
};
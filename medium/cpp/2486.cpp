// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

class Solution
{
public:
    int appendCharacters(std::string s, std::string t)
    {
        auto pt = 0;

        for (auto pos = 0; pos < std::size(s) && pt < std::size(t); pos++)
        {
            if (s[pos] == t[pt])
            {
                pt++;
            }
        }

        return std::size(t) - pt;
    }
};
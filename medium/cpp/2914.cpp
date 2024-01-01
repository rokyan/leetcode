// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/

class Solution
{
public:
    int minChanges(std::string s)
    {
        const auto n = std::size(s);

        auto res = 0;

        for (auto i = 0; i < n; i += 2)
        {
            if (s[i] == '0' && s[i + 1] == '1' ||
                s[i] == '1' && s[i + 1] == '0')
            {
                res++;
            }
        }

        return res;
    }
};
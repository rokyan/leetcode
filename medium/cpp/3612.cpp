// https://leetcode.com/problems/process-string-with-special-operations-i/description/

class Solution
{
public:
    std::string processStr(const std::string& s)
    {
        std::string res;
        res.reserve(std::size(s));

        for (auto c : s)
        {
            if (c == '*')
            {
                if (!res.empty())
                {
                    res.pop_back();
                }
            }
            else if (c == '#')
            {
                res += res;
            }
            else if (c == '%')
            {
                std::ranges::reverse(res);
            }
            else
            {
                res.push_back(c);
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution
{
public:
    string minRemoveToMakeValid(std::string s)
    {
        std::vector<char> taken(std::size(s));

        auto balance = 0;

        for (auto i = 0; i < std::size(s); i++)
        {
            if (s[i] == '(')
            {
                taken[i] = true;
                balance++;
            }
            else if (s[i] == ')')
            {
                if (balance > 0)
                {
                    taken[i] = true;
                    balance--;
                }
            }
            else
            {
                taken[i] = true;
            }
        }

        for (auto i = static_cast<int>(std::size(s)) - 1; i >= 0 && balance > 0; i--)
        {
            if (s[i] == '(')
            {
                balance--;
                taken[i] = false;
            }
        }

        std::string res;
        res.reserve(std::size(s));

        for (auto i = 0; i < std::size(s); i++)
        {
            if (taken[i])
            {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
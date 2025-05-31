// https://leetcode.com/problems/resulting-string-after-adjacent-removals/description/

class Solution
{
public:
    std::string resultingString(const std::string& s)
    {
        std::string res;
        res.reserve(std::size(s));
        res.push_back(s.front());

        for (auto i = 1; i < std::size(s); i++)
        {
            if (!res.empty())
            {
                auto a = res.back();
                auto b = s[i];

                if (a > b)
                { 
                    std::swap(a, b);
                }

                if (b - a == 1 || a == 'a' && b == 'z')
                {
                    res.pop_back();
                }
                else
                {
                    res.push_back(s[i]);
                }
            }
            else
            {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
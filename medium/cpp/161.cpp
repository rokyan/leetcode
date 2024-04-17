// https://leetcode.com/problems/one-edit-distance/description/

class Solution
{
public:
    bool isOneEditDistance(std::string s, std::string t)
    {
        if (std::size(s) == std::size(t))
        {
            auto cnt = 0;

            for (auto i = 0; cnt <= 1 && i < std::size(s); i++)
            {
                if (s[i] != t[i])
                {
                    cnt++;
                }
            }

            return cnt == 1;
        }

        if (std::size(s) > std::size(t))
        {
            std::swap(s, t);
        }

        if (std::size(s) + 1 != std::size(t))
        {
            return false;
        }

        auto i = 0;

        while (i < std::size(s) && s[i] == t[i])
        {
            i++;
        }

        if (i == std::size(s))
        {
            return true;
        }

        while (i < std::size(s) && s[i] == t[i + 1])
        {
            i++;
        }

        return i == std::size(s);
    }
};
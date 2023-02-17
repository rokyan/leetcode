// https://leetcode.com/problems/adding-spaces-to-a-string/description/

class Solution
{
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces)
    {
        std::string res;
        res.reserve(std::size(s) + std::size(spaces));

        for (auto i = 0, p = 0; i < std::size(s); i++)
        {
            if (p < std::size(spaces) && i == spaces[p])
            {
                p++;
                res.push_back(' ');
            }

            res.push_back(s[i]);
        }

        return res;
    }
};
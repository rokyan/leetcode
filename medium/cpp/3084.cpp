// https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/

class Solution
{
public:
    long long countSubstrings(std::string s, char c)
    {
        auto res = 0LL;

        for (auto i = 0, cnt = 0; i < std::size(s); i++)
        {
            if (s[i] == c)
            {
                res += ++cnt;
            }
        }

        return res;
    }
};
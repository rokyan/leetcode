// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/

class Solution
{
public:
    int countSubstrings(std::string s, std::string t)
    {
        auto res = 0;

        for (auto i = 0; i < std::size(s); i++)
        {
            for (auto j = 0; j < std::size(t); j++)
            {
                auto len = 0;
                auto diff = 0;
                auto cnt = 0;

                while (i + len < std::size(s) && j + len < std::size(t) && diff < 2)
                {
                    if (s[i + len] != t[j + len])
                    {
                        diff++;
                    }

                    if (diff == 1)
                    {
                        cnt++;
                    }

                    len++;
                }

                res += cnt;
            }
        }

        return res;
    }
};
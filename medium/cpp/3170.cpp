// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/

class Solution
{
public:
    std::string clearStars(std::string s)
    {
        const auto n = std::size(s);

        std::vector<std::vector<int>> st(26);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                for (auto j = 0; j < 26; j++)
                {
                    if (!st[j].empty())
                    {
                        s[st[j].back()] = '#';
                        st[j].pop_back();
                        break;
                    }
                }

                s[i] = '#';
            }
            else
            {
                st[s[i] - 'a'].push_back(i);
            }
        }

        s.erase(std::remove(std::begin(s), std::end(s), '#'), std::end(s));

        return s;
    }
};
// https://leetcode.com/problems/minimum-window-subsequence/description/

class Solution
{
public:
    std::string minWindow(std::string s1, std::string s2)
    {
        const auto n = std::size(s1);

        std::vector<std::vector<int>> last(n, std::vector<int>(26, -1));

        for (auto i = 0; i < n; i++)
        {
            if (i > 0)
            {
                last[i] = last[i - 1];
            }

            last[i][s1[i] - 'a'] = i;
        }

        std::string res;

        for (auto i = static_cast<int>(std::size(s2)) - 1; i < n; i++)
        {
            if (s1[i] == s2.back())
            {
                auto pos = i;
                auto j = static_cast<int>(std::size(s2)) - 1;

                for (;j >= 0 && pos >= 0; j--)
                {
                    pos = last[pos][s2[j] - 'a'] - 1;
                }

                if (pos != -2 && j == -1 && (res.empty() || i - pos < std::size(res)))
                {
                    res = s1.substr(pos + 1, i - pos);
                }
            }
        }

        return res;
    }
};
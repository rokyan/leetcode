// https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

class Solution
{
public:
    std::string shortestBeautifulSubstring(std::string s, int k)
    {
        std::string res;

        for (auto l = 0, r = 0, c = 0; r < std::size(s); r++)
        {
            c += s[r] == '1';

            while (c > k || c == k && s[l] == '0')
            {
                c -= s[l++] == '1';
            }

            if (c == k)
            {
                if (res.empty() || r - l + 1 < std::size(res))
                {
                    res = s.substr(l, r - l + 1);
                }
                else if (r - l + 1 == std::size(res))
                {
                    const auto cand = s.substr(l, r - l + 1);

                    if (cand < res)
                    {
                        res = cand;
                    }
                }
            }
        }

        return res;
    }
};
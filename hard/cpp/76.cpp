// https://leetcode.com/problems/minimum-window-substring/description/

class Solution
{
public:
    std::string minWindow(std::string s, std::string t)
    {
        std::array<int, 52> cnts{ 0 };
        std::array<int, 52> cntt{ 0 };

        auto to_num = [](char c)
        {
            if (c >= 'a' && c <= 'z')
            {
                return c - 'a';
            }

            return 26 + c - 'A';
        };

        for (auto c : t)
        {
            cntt[to_num(c)]++;
        }

        auto pos = -1;
        auto len = 0;

        for (auto l = 0, r = 0; r < std::size(s); r++)
        {
            cnts[to_num(s[r])]++;

            while (l <= r && cnts[to_num(s[l])] > cntt[to_num(s[l])])
            {
                cnts[to_num(s[l])]--;
                l++; 
            }

            auto check = true;

            for (auto c = 0; c < 52; c++)
            {
                if (cntt[c] > cnts[c])
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                if (pos == -1 || r - l + 1 < len)
                {
                    pos = l;
                    len = r - l + 1;
                }
            }
        }

        if (pos == -1)
        {
            return "";
        }

        return s.substr(pos, len);
    }
};
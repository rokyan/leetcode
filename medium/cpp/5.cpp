// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        const auto sz = std::size(s);

        std::string ans;

        for (auto pos = 0; pos < sz; pos++)
        {
            auto len = 0;

            while (pos - len >= 0 && pos + len < sz && s[pos - len] == s[pos + len])
            {
                len++;
            }

            if (2 * len - 1 > std::size(ans))
            {
                ans = s.substr(pos - len + 1, 2 * len - 1);
            }
        }

        for (auto pos = 0; pos < sz; pos++)
        {
            auto len = 0;

            while (pos - len >= 0 && pos + len + 1 < sz && s[pos - len] == s[pos + len + 1])
            {
                len++;
            }

            if (len > 0)
            {
                if (2 * len > std::size(ans))
                {
                    ans = s.substr(pos - len + 1, 2 * len);
                }
            }
        }

        return ans;
    }
};
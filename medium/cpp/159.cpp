// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(std::string s)
    {
        const auto ord = [](char c) {
            if (c >= 'a' && c <= 'z')
            {
                return c - 'a';
            }

            return c - 'A' + 26;
        };

        std::array<int, 26 * 2> freq{ 0 };
        auto res = 0;

        for (auto l = 0, r = 0, d = 0; r < std::size(s); r++)
        {
            if (freq[ord(s[r])]++ == 0)
            {
                d++;
            }

            while (d == 3)
            {
                if (freq[ord(s[l++])]-- == 1)
                {
                    d--;
                }
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k)
    {
        std::array<int, 256> freq{ 0 };
        auto res = 0;

        for (auto l = 0, r = 0, d = 0; r < std::size(s); r++)
        {
            if (freq[s[r]]++ == 0)
            {
                d++;
            }

            while (d == k + 1)
            {
                if (freq[s[l++]]-- == 1)
                {
                    d--;
                }
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
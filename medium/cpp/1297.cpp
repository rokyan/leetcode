// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

class Solution
{
public:
    int maxFreq(std::string s, int maxLetters, int minSize, int maxSize)
    {
        std::array<int, 26> cnt{ 0 };

        std::map<std::string_view, int> freq;
        auto res = 0;

        for (auto l = 0, r = 0, diff = 0; r < std::size(s); r++)
        {
            if (cnt[s[r] - 'a']++ == 0)
            {
                diff++;
            }

            while (diff > maxLetters)
            {
                if (cnt[s[l++] - 'a']-- == 1)
                {
                    diff--;
                }
            }

            if (r - l + 1 >= minSize)
            {
                res = std::max(res, ++freq[std::string_view{ s }.substr(r - minSize + 1, minSize)]);
            }
        }

        return res;
    }
};
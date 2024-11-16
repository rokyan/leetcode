// https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/description/

class Solution
{
public:
    long long validSubstringCount(const std::string& word1, const std::string& word2)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : word2)
        {
            freq[c - 'a']--;
        }

        auto res = 0LL;
        auto b = std::count_if(std::cbegin(freq), std::cend(freq),
            [](auto c) { return c < 0; });

        for (auto l = 0, r = 0; l < std::size(word1); l++)
        {
            while (r < std::size(word1) && b > 0)
            {
                if (freq[word1[r++] - 'a']++ == -1)
                {
                    b--;
                }
            }

            if (b == 0)
            {
                res += std::size(word1) - r + 1;
            }

            if (freq[word1[l] - 'a']-- == 0)
            {
                b++;
            }
        }

        return res;
    }
};
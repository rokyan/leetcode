// https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/

class Solution
{
public:
    long long validSubstringCount(const std::string& word1, const std::string& word2)
    {
        std::array<int, 26> freq{ 0 };
        auto neg = 0;

        for (auto c : word2)
        {
            if (freq[c - 'a']-- == 0)
            {
                neg++;
            }
        }

        const auto n = std::size(word1);

        auto res = 0LL;

        for (auto l = 0, r = 0; l < n; l++)
        {
            while (r < n && neg)
            {
                if (++freq[word1[r++] - 'a'] == 0)
                {
                    neg--;
                }
            }

            if (!neg)
            {
                res += n - r + 1;
            }

            if (freq[word1[l] - 'a']-- == 0)
            {
                neg++;
            }
        }

        return res;
    }
};
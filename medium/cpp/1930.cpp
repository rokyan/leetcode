// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

class Solution
{
public:
    int countPalindromicSubsequence(std::string s)
    {
        const auto ord = [](char c) { return c - 'a'; };

        std::array<char, 26> seen_one{ 0 };
        std::array<char, 26 * 26 + 26> seen_two{ 0 };

        std::unordered_set<int> probe;

        for (auto symb : s)
        {
            const auto c = ord(symb);

            for (auto i = 0; i < 26; i++)
            {
                const auto t = 26 * c + i;

                if (seen_two[t])
                {
                    probe.insert(t);
                }
            }

            for (auto i = 0; i < 26; i++)
            {
                if (seen_one[i])
                {
                    seen_two[i * 26 + c] = true;
                }
            }

            seen_one[c] = true;
        }

        return std::size(probe);
    }
};
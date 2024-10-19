// https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/

class Solution
{
public:
    int numberOfSpecialChars(const std::string& word)
    {
        std::array<int, 26> first;
        std::array<int, 26> last;

        for (auto i = 0; i < 26; i++)
        {
            first[i] = last[i] = -1;
        }

        for (auto i = 0; i < std::size(word); i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                const auto c = word[i] - 'a';
                last[c] = i;
            }
            else
            {
                const auto c = word[i] - 'A';

                if (first[c] == -1)
                {
                    first[c] = i;
                }
            }
        }

        auto res = 0;

        for (auto i = 0; i < 26; i++)
        {
            if (first[i] != -1 && last[i] != -1 && last[i] < first[i])
            {
                res++;
            }
        }

        return res;
    }
};
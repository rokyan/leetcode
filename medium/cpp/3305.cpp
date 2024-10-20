// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/description/

class Solution
{
public:
    int countOfSubstrings(const std::string& word, int k)
    {
        const auto n = std::size(word);

        auto res = 0;

        const std::string_view vowels = "aeiou";

        for (auto l = 0; l < n; l++)
        {
            std::unordered_set<char> met;
            auto cnt = 0;

            for (auto r = l; r < n && cnt <= k; r++)
            {
                if (vowels.find(word[r]) != std::string_view::npos)
                {
                    met.insert(word[r]);
                }
                else
                {
                    cnt++;
                }

                if (std::size(met) == 5 && cnt == k)
                {
                    res++;
                }
            }
        }

        return res;
    }
};
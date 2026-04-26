// https://leetcode.com/problems/sort-vowels-by-frequency/description/

class Solution
{
public:
    std::string sortVowels(const std::string& s)
    {
        std::unordered_map<char, int> freq;
        std::unordered_map<char, int> firstPos;

        std::string_view vowels{"aeiou"};
        std::vector<char> all;

        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.find(s[i]) != std::string_view::npos)
            {
                freq[s[i]]++;

                if (!firstPos.contains(s[i]))
                {
                    firstPos[s[i]] = i;
                }

                all.push_back(s[i]);
            }
        }

        std::ranges::sort(all, [&](char a, char b) {
            return freq[a] < freq[b] || freq[a] == freq[b] && firstPos[a] > firstPos[b];
        });

        std::string res;
        res.reserve(s.size());

        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.find(s[i]) == std::string_view::npos)
            {
                res.push_back(s[i]);
            }
            else
            {
                res.push_back(all.back());
                all.pop_back();
            }
        }

        return res;
    }
};
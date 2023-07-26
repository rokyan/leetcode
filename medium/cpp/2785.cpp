// https://leetcode.com/problems/sort-vowels-in-a-string/description/

class Solution
{
public:
    string sortVowels(std::string s)
    {
        std::string_view all_vowels = "aeiou";

        std::string vowels;
        vowels.reserve(std::size(s));

        std::copy_if(std::begin(s), std::end(s), std::back_inserter(vowels), [&all_vowels](char c) {
            return all_vowels.find(std::tolower(c)) != std::string_view::npos;
        });

        std::sort(std::begin(vowels), std::end(vowels));

        auto p = 0;

        for (auto& c : s)
        {
            if (all_vowels.find(std::tolower(c)) != std::string_view::npos)
            {
                c = vowels[p++];
            }
        }

        return s;
    }
};
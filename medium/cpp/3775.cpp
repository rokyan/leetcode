// https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/

class Solution
{
public:
    std::string reverseWords(const std::string& s)
    {
        std::istringstream iss{s};

        std::string token;
        std::getline(iss, token, ' ');

        const unsigned vowels_count = count_vowels(token);

        std::string res;
        res.reserve(size(s));

        res += token;

        while (std::getline(iss, token, ' '))
        {
            if (count_vowels(token) == vowels_count)
            {
                std::ranges::reverse(token);
            }

            res.push_back(' ');
            res += token;
        }

        return res;
    }

private:
    unsigned count_vowels(const std::string& s)
    {
        static std::array<char, 5> vowels{'a', 'e', 'i', 'o', 'u'};

        return std::count_if(cbegin(s), cend(s), [](char c) {
            return std::find(cbegin(vowels), cend(vowels), c) != cend(vowels);
        });
    }
};
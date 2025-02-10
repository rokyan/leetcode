class Solution
{
public:
    std::string toGoatLatin(const std::string& sentence)
    {
        std::string_view vowels{"aeiouAEIOU"};

        std::string res;
        res.reserve(std::size(sentence));
        std::string word;
        auto idx = 1;

        for (auto i = 0; i < std::size(sentence); i++)
        {
            if (sentence[i] == ' ' || i + 1 == std::size(sentence))
            {
                if (i + 1 == std::size(sentence))
                {
                    word.push_back(sentence[i]);
                }

                if (vowels.find(word.front()) == std::string_view::npos)
                {
                    std::rotate(std::begin(word), std::next(std::begin(word)), std::end(word));
                }

                word.push_back('m');
                word.push_back('a');

                for (auto t = 0; t < idx; t++)
                {
                    word.push_back('a');
                }

                for (auto c : word)
                {
                    res.push_back(c);
                }

                if (i + 1 < std::size(sentence))
                {
                    res.push_back(' ');
                }

                word.clear();
                idx++;
            }
            else
            {
                word.push_back(sentence[i]);
            }
        }

        return res;
    }
};
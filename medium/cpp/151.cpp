class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::vector<std::string> words;
        std::string word;

        for (auto c : s)
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word.push_back(c);
            }
        }

        if (!word.empty())
        {
            words.push_back(word);
        }

        std::reverse(std::begin(words), std::end(words));

        std::string res;

        for (auto&& word : words)
        {
            if (!res.empty())
            {
                res.push_back(' ');
            }

            res += word;
        }

        return res;
    }
};
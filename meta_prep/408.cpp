class Solution
{
public:
    bool validWordAbbreviation(const std::string& word, const std::string& abbr)
    {
        auto cur = 0;
        auto pos = 0;

        for (auto i = 0; i < std::size(abbr); i++)
        {
            if (abbr[i] >= 'a' && abbr[i] <= 'z')
            {
                pos += cur;
                cur = 0;

                if (pos >= std::size(word) || word[pos] != abbr[i])
                {
                    return false;
                }

                pos++;
            }
            else
            {
                if (cur == 0 && abbr[i] == '0')
                {
                    return false;
                }

                cur = 10 * cur + abbr[i] - '0';
            }
        }

        return pos + cur == std::size(word);
    }
};
// https://leetcode.com/problems/sentence-similarity-iii/description/

class Solution
{
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2)
    {
        auto tokens1 = split(sentence1);
        auto tokens2 = split(sentence2);

        if (std::size(tokens1) > std::size(tokens2))
        {
            std::swap(tokens1, tokens2);
        }

        for (auto take = 0; take <= std::size(tokens1); take++)
        {
            auto pref_match = true;

            for (auto i = 0; i < take; i++)
            {
                if (tokens1[i] != tokens2[i])
                {
                    pref_match = false;
                    break;
                }
            }

            if (pref_match)
            {
                const auto rem = std::size(tokens1) - take;
                auto suff_match = true;

                for (auto i = 0; i < rem; i++)
                {
                    if (tokens1[std::size(tokens1) - 1 - i] != tokens2[std::size(tokens2) - 1 - i])
                    {
                        suff_match = false;
                        break;
                    }
                }

                if (suff_match)
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    std::vector<std::string> split(const std::string& s)
    {
        std::vector<std::string> tokens;
        tokens.reserve(std::size(s));

        std::string acc;

        for (auto c : s)
        {
            if (c == ' ')
            {
                tokens.push_back(acc);
                acc.clear();
            }
            else
            {
                acc.push_back(c);
            }
        }

        tokens.push_back(acc);

        return tokens;
    }
};
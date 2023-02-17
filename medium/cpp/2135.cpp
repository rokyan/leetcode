// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/

class Solution
{
public:
    int wordCount(std::vector<std::string>& startWords, std::vector<std::string>& targetWords)
    {
        std::unordered_set<std::string> probe;

        for (auto& word : startWords)
        {
            std::sort(std::begin(word), std::end(word));
            probe.insert(word);
        }

        auto res = 0;

        for (auto& word : targetWords)
        {
            std::sort(std::begin(word), std::end(word));

            for (auto i = 0; i < std::size(word); i++)
            {
                auto modified = word;
                modified.erase(i, 1);

                if (probe.find(modified) != std::end(probe))
                {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};
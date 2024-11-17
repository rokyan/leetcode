// https://leetcode.com/problems/longest-word-in-dictionary/description/

class Solution
{
public:
    std::string longestWord(std::vector<std::string>& words)
    {
        std::sort(std::begin(words), std::end(words), [](const auto& left, const auto& right) {
            return std::size(left) < std::size(right) ||
                std::size(left) == std::size(right) && left < right;
        });

        std::unordered_set<std::string> all;
        all.insert("");

        std::string res;

        for (auto& word : words)
        {
            auto c = word.back();
            word.pop_back();

            if (all.find(word) != std::end(all))
            {
                word.push_back(c);
                all.insert(word);

                if (std::size(res) < std::size(word))
                {
                    res = word;
                }
            }
        }

        return res;
    }
};
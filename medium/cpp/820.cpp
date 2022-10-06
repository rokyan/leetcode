// https://leetcode.com/problems/short-encoding-of-words/

class Solution
{
public:
    int minimumLengthEncoding(std::vector<std::string>& words)
    {      
        std::unordered_set<std::string> words_set(std::begin(words), std::end(words));
        
        for (const auto& word : words)
        {
            for (std::size_t pos = 1; pos < std::size(word); pos++)
            {
                const auto suff = word.substr(pos);
                words_set.erase(suff);
            }
        }
        
        return std::accumulate(std::begin(words_set), std::end(words_set), 0, [](int acc, const std::string& word) {
            return acc + std::size(word) + 1;
        });
    }
};
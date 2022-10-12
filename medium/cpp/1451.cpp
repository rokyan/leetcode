// https://leetcode.com/problems/rearrange-words-in-a-sentence/

class Solution
{
public:
    std::string arrangeWords(std::string text)
    {        
        std::vector<std::string> words;
        std::string word;
        
        for (std::size_t pos = 0; pos < std::size(text); pos++)
        {
            if (text[pos] == ' ')
            {                
                word[0] = std::tolower(word[0]);
                words.push_back(word);
                word.clear();
            }
            else
            {
                word.push_back(text[pos]);
            }
        }

        word[0] = std::tolower(word[0]);
        words.push_back(word);      
        
        std::stable_sort(std::begin(words), std::end(words),
            [](const auto& w1, const auto& w2) { return std::size(w1) < std::size(w2); });
        
        std::string rearranged(std::size(text), '\0');
        std::size_t pos = 0;
        
        for (const auto& word : words)
        {
            for (std::size_t ppos = 0; ppos < std::size(word); ppos++)
            {
                rearranged[pos++] = word[ppos];
            }
            
            if (pos != std::size(text))
            {
                rearranged[pos++] = ' ';
            }
        }
        
        rearranged[0] = std::toupper(rearranged[0]);
        
        return rearranged;
    }
};
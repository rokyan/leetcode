// https://leetcode.com/problems/print-words-vertically/

class Solution
{
public:
    std::vector<std::string> printVertically(std::string s)
    {
        std::istringstream is(s);
        
        std::string word;
        
        std::vector<std::string> words;
        
        std::size_t max_len = 0;
        
        while (is >> word)
        {
            words.push_back(word);
            max_len = std::max(max_len, std::size(word));
        }
        
        std::vector<std::string> reord(max_len);
        
        for (const auto& word : words)
        {
            for (std::size_t pos = 0; pos < std::size(word); pos++)
            {
                reord[pos] += word[pos];
            }
            
            for (std::size_t pos = std::size(word); pos < max_len; pos++)
            {
                reord[pos] += " ";
            }
        }
        
        for (auto& rw : reord)
        {
            while (std::isspace(rw.back()))
            {
                rw.pop_back();
            }
        }
        
        return reord;
    }
};
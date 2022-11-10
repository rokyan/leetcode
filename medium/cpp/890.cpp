// https://leetcode.com/problems/find-and-replace-pattern/

class Solution
{
public:
    std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern)
    { 
        remap(pattern);
        
        std::vector<string> answer;
        
        for (const auto& word : words)
        {
            string remapped_word { word };
            remap(remapped_word);
            
            if (remapped_word == pattern)
            {
                answer.push_back(word);
            }
        }
       
        return answer;
    }
    
private:
    void remap(std::string& word)
    {
        int mapping[26] {};
        
        auto mapped_to = 'a';
            
        for (auto& c : word)
        {
            if (mapping[c - 'a'] == 0)
            {
                mapping[c - 'a'] = mapped_to++;
            }

            c = mapping[c - 'a'];
        }
    }
};
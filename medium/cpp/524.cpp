// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

class Solution
{
public:
    std::string findLongestWord(std::string s, std::vector<std::string>& d)
    {       
        std::sort(std::begin(d), std::end(d), [](const std::string& lhs, const std::string& rhs) {
            return lhs.size() > rhs.size() || lhs.size() == rhs.size() && lhs < rhs;
        });

        std::string answer;
        
        for (const auto& word : d)
        {
            if (check(word, s))
            {
                answer = word;
                break;
            }
        }
        
        return answer;
    }

private:   
    bool check(const std::string& word, const std::string& s)
    {
        std::size_t i = 0;

        for (std::size_t j = 0; j < s.size() && i < word.size(); ++j)
        {
            if (word[i] == s[j])
            {
                ++i;
            }
        }
        
        return (i == word.size());
    }
};
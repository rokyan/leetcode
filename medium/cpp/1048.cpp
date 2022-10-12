// https://leetcode.com/problems/longest-string-chain/

class Solution
{
public:
    int longestStrChain(std::vector<std::string>& words)
    {
        const auto n = std::size(words);
        
        std::sort(std::begin(words), std::end(words),
            [](const auto& s1, const auto& s2) { return std::size(s1) < std::size(s2); });
        
        std::vector<int> dist(n, 1);
        
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            
            while (j >= 0)
            {
                if (std::size(words[j]) + 1 < std::size(words[i]))
                {
                    break;
                }
                
                if (is_pred(words[j], words[i]))
                {
                    dist[i] = std::max(dist[i], dist[j] + 1);
                }
                
                j--;
            }
        }
        
        return *std::max_element(std::begin(dist), std::end(dist));
    }
    
private:
    bool is_pred(const std::string& cand, std::string word)
    {
        if (std::size(cand) + 1 != std::size(word))
        {
            return false;
        }
        
        std::size_t pos = 0;
        
        while (pos < std::size(cand) && cand[pos] == word[pos])
        {
            pos++;
        }
        
        if (pos == std::size(cand))
        {
            return true;
        }
        
        while (pos < std::size(cand) && cand[pos] == word[pos + 1])
        {
            pos++;
        }
        
        return pos == std::size(cand);
    }
};
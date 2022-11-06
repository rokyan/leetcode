// https://leetcode.com/problems/word-break/

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict)
    {
        std::vector<int> dp(std::size(s));
        
        for (std::size_t pos = 0; pos < std::size(s); pos++)
        {
            for (const auto& word : wordDict)
            {
                if (std::size(word) <= pos + 1)
                {
                    const std::size_t start_pos = pos + 1 - std::size(word);
                    
                    if (s.substr(start_pos, std::size(word)) == word && (start_pos == 0 || dp[start_pos - 1]))
                    {
                        dp[pos] = true;
                        break;
                    }
                }
            }
        }
        
        return dp.back();
    }
};
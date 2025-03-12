class Solution
{
public:
    bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict)
    {
        const auto n = std::size(s);
        std::string_view sw{s};

        std::vector<int> dp(n);
        
        for (std::size_t pos = 0; pos < n; pos++)
        {
            for (const auto& word : wordDict)
            {
                if (std::size(word) <= pos + 1)
                {
                    const auto start_pos = pos + 1 - std::size(word);
                    
                    if (sw.substr(start_pos, std::size(word)) == word
                        && (start_pos == 0 || dp[start_pos - 1]))
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
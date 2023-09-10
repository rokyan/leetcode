// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        const auto len = std::size(s);
        
        std::vector<std::vector<int>> dp(len, std::vector<int>(len));
        
        for (auto i = 0; i < len; ++i)
        {
            dp[i][i] = 1;
        }
        
        for (auto i = 2; i <= len; ++i)
        {
            for (auto j = 0; j + i - 1 < len; ++j)
            {
                const auto first = j;
                const auto last = j + i - 1;
                
                dp[first][last] = std::max(dp[first + 1][last], dp[first][last - 1]);
                
                if (s[first] == s[last])
                {
                    auto cur = 2;
                    
                    if (first + 1 <= last - 1)
                    {
                        cur += dp[first + 1][last - 1];
                    }
                    
                    dp[first][last] = std::max(dp[first][last], cur);
                }
            }
        }
        
        return dp[0][len - 1];
    }
};
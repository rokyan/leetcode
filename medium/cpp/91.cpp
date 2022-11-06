// https://leetcode.com/problems/decode-ways/

class Solution
{
public:
    int numDecodings(std::string s)
    {       
        const auto len = std::size(s);
        
        std::vector<int> dp(len);
        
        for (std::size_t pos = 0; pos < len; pos++)
        {
            if (s[pos] != '0')
            {
                dp[pos] = pos > 0 ? dp[pos - 1] : 1;
            }
            
            if (pos > 0 && s[pos - 1] != '0')
            {
                const auto num = s[pos] - '0' + 10 * (s[pos - 1] -'0');
                
                if (num >= 1 && num <= 26)
                {
                    dp[pos] += pos > 1 ? dp[pos - 2] : 1;
                }
            }
        }
        
        return dp.back();
    }
};
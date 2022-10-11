// https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution
{
public:
    int minFlipsMonoIncr(std::string s)
    {
        const auto n = std::size(s);
        
        int zeroes = std::count_if(std::begin(s), std::end(s), [](char c) { return c == '0'; });
        int ones = 0;
        
        int ans = n + 1;
        
        for (std::size_t pos = 0; pos < n; pos++)
        {
            ans = std::min(ans, zeroes + ones);
            
            if (s[pos] == '0')
            {
                zeroes--;
            }
            else
            {
                ones++;
            }
        }
        
        ans = std::min(ans, zeroes + ones);
        
        return ans;
    }
};
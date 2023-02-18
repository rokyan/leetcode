// https://leetcode.com/problems/total-appeal-of-a-string/description/

class Solution
{
public:
    long long appealSum(string s)
    {
        std::size_t last[26] = { 0 };
        
        long long ans = 0;
        
        for (std::size_t pos = 0; pos < std::size(s); pos++)
        {
            last[s[pos] - 'a'] = pos + 1;
            
            for (int c = 0; c < 26; c++)
            {
                ans += last[c];
            }
        }
        
        return ans;
    }
};
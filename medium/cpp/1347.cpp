// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution
{
public:
    int minSteps(std::string s, std::string t)
    {
        int counts[26] = { 0 };
        
        for (std::size_t pos = 0; pos < std::size(s); pos++)
        {
            counts[s[pos] - 'a']++;
        }
        
        int result = 0;
        
        for (std::size_t pos = 0; pos < std::size(t); pos++)
        {
            if (counts[t[pos] - 'a'] > 0)
            {
                counts[t[pos] - 'a']--;
            }
            else
            {
                result++;
            }
        }
        
        return result;
    }
};
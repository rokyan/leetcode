// https://leetcode.com/problems/palindromic-substrings/

class Solution
{
public:
    int countSubstrings(std::string s)
    {
        int ans = 0;
        
        const int n = std::size(s);
        
        for (int i = 0; i < n; i++)
        {
            int j = i;
            int k = i;
            
            while (j >= 0 && k< n && s[j] == s[k])
            {
                ans++;
                j--;
                k++;
            }
        }
        
        for (int i = 0; i + 1 < n; i++)
        {
            int j = i;
            int k = i + 1;
            
            while (j >= 0 && k < n && s[j] == s[k])
            {
                ans++;
                j--;
                k++;
            }
        }
        
        return ans;
    }
};
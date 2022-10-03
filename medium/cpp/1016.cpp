// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

class Solution
{
public:
    bool queryString(std::string s, int n)
    {
        const auto s_len = std::size(s);
        
        if (s_len * (s_len + 1) / 2 < n)
        {
            return false;
        }
        
        std::unordered_set<int> un;
        
        for (int len = 0; len < 32; len++)
        {
            for (int i = 0; i + len - 1 < s_len; i++)
            {
                if (s[i] == '0')
                {
                    continue;
                }
                
                int num = 0;
                
                for (int j = i; j <= i + len - 1; j++)
                {
                    num <<= 1;
                    num += s[j] == '1';
                    
                    if (num > n)
                    {
                        break;
                    }
                }
                
                if (num <= n)
                {
                    un.insert(num);
                }
            }
        }
        
        for (int num = 1; num <= n; num++)
        {
            if (un.find(num) == un.end())
            {
                return false;
            }
        }
        
        return true;
    }
};
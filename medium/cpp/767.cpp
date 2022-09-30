// https://leetcode.com/problems/reorganize-string/

class Solution
{
public:
    std::string reorganizeString(std::string s)
    {
        int cnt[26] = {};
        
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }
               
        const int n = std::size(s);
        
        std::string res;
        res.reserve(n);
        
        for (int i = 0; i < n; i++)
        {
            char c = -1;
            
            for (int j = 0; j < 26; j++)
            {
                if (cnt[j] > 0 && (i == 0 || res[i - 1] != j + 'a'))
                {
                    if (c == -1 || cnt[j] > cnt[c])
                    {
                        c = j;
                    }
                }
            }
            
            if (c == -1)
            {
                return "";
            }
            
            cnt[c]--;
            res.push_back(c + 'a');
        }
        
        return res;
    }
};
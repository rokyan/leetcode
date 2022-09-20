// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution
{
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        const auto len = std::size(p);
        
        if (len > std::size(s))
        {
            return {};
        }
        
        std::vector<int> p_cnt(26);
        
        for (std::size_t i = 0; i < len; i++)
        {
            p_cnt[p[i] - 'a']++;
        }
        
        std::vector<int> s_cnt(26);
        
        for (std::size_t i = 0; i + 1 < len; i++)
        {
            s_cnt[s[i] - 'a']++;
        }
        
        std::vector<int> ans;
        
        for (std::size_t i = len - 1; i < std::size(s); i++)
        {
            const auto start = i + 1 - len;
            
            if (start > 0)
            {
                s_cnt[s[start - 1] - 'a']--;
            }
            
            s_cnt[s[i] - 'a']++;
            
            if (p_cnt == s_cnt)
            {
                ans.push_back(start);
            }
        }
        
        return ans;
    }
};
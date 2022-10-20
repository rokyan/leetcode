// https://leetcode.com/problems/remove-duplicate-letters/

class Solution
{
public:
    std::string removeDuplicateLetters(std::string s)
    {
        std::vector<int> counts(26);
        
        for (auto c : s)
        {
            counts[c - 'a']++;
        }
        
        std::vector<char> used(26);
        
        std::vector<char> st;
        
        for (auto c : s)
        {
            if (!used[c - 'a'])
            {
                while (!st.empty() && st.back() >= c && counts[st.back() - 'a'] > 0)
                {
                    used[st.back() - 'a'] = false;
                    st.pop_back();
                }
                
                used[c - 'a'] = true;
                st.push_back(c);
            }
            
            counts[c - 'a']--;
        }
        
        return std::string{ std::begin(st), std::end(st) };    
    }
};
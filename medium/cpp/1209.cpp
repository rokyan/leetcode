// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution
{
public:
    std::string removeDuplicates(std::string s, int k)
    {
        std::stack<std::pair<char, int>> st;
        
        for (std::size_t pos = 0; pos < std::size(s); pos++)
        {
            if (st.empty() || st.top().first != s[pos])
            {
                st.push({ s[pos], 1 });
            }
            else
            {
                st.top().second++;
            }
            
            if (st.top().second == k)
            {
                st.pop();
            }
        }
        
        std::string res;
        res.reserve(std::size(s));
        
        while (!st.empty())
        {
            auto p = st.top();
            st.pop();
            
            for (int times = 0; times < p.second; times++)
            {
                res.push_back(p.first);
            }
        }
        
        std::reverse(std::begin(res), std::end(res));
        
        return res;
    }
};
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution
{
public:
    std::string reverseParentheses(std::string s)
    {
        std::vector<int> p_st;
        std::vector<char> s_st;
        std::vector<char> tmp;
        
        for (std::size_t i = 0; i < std::size(s); i++)
        {
            if (s[i] == '(')
            {
                p_st.push_back(i);
            }
            else if (s[i] == ')')
            {
                const auto pos = p_st.back();
                p_st.pop_back();
                
                tmp.clear();
                
                for (std::size_t j = pos + 1; j < i; j++)
                {
                    if (s[j] != '(' && s[j] != ')')
                    {
                        tmp.push_back(s_st.back());
                        s_st.pop_back();
                    }
                }
                
                for (auto c : tmp)
                {
                    s_st.push_back(c);
                }
            }
            else
            {
                s_st.push_back(s[i]);
            }
        }
        
        return std::string(std::begin(s_st), std::end(s_st));
    }
};
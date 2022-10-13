// https://leetcode.com/problems/score-of-parentheses/

class Solution
{
public:
    int scoreOfParentheses(std::string s)
    {
        std::vector<int> st;
        
        int acc = 0;
        
        for (auto c : s)
        {
            if (c == '(')
            {
                st.push_back(acc);
                acc = 0;
            }
            else
            {
                acc = st.back() + std::max(2 * acc, 1);
                st.pop_back();
            }
        }
        
        return acc;
    }
};
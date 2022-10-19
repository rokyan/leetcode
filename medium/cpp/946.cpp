// https://leetcode.com/problems/validate-stack-sequences/

class Solution
{
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped)
    {
        std::vector<int> st;        
        
        for (std::size_t i = 0, j = 0; i < std::size(pushed) && j < std::size(popped); i++)
        {
            st.push_back(pushed[i]);
            
            while (j < std::size(popped) && !st.empty() && st.back() == popped[j])
            {
                st.pop_back();
                j++;
            }
        }
        
        return st.empty();
    }
};
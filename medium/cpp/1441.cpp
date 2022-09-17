// https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution
{
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n)
    {       
        std::vector<int> st;
        st.reserve(n);
        
        std::vector<std::string> answer;
        answer.reserve(n);
        
        for (auto value = 1, pos = 0, last = -1; value <= n && pos < std::size(target); value++)
        {           
            if (target[pos] == value)
            {
                while (!st.empty() && st.back() != last)
                {
                    answer.push_back("Pop");
                    st.pop_back();
                }
                
                last = target[pos++];
            }
            
            answer.push_back("Push");
            st.push_back(value);
        }
        
        return answer;
    }
};
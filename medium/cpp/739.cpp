// https://leetcode.com/problems/daily-temperatures/

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        const int n = std::size(temperatures);
        
        std::vector<int> result(n);
        
        std::vector<int> st;
        
        for (int pos = n - 1; pos >= 0; pos--)
        {
            const int temp = temperatures[pos];
            
            while (!st.empty() && temperatures[st.back()] <= temp)
            {
                st.pop_back();
            }
            
            result[pos] = st.empty() ? 0 : st.back() - pos;
            
            st.push_back(pos);
        }
        
        return result;
    }
};
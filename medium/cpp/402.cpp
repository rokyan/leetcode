// https://leetcode.com/problems/remove-k-digits/

class Solution
{
public:
    std::string removeKdigits(std::string num, int k)
    {
        std::vector<char> st;
        
        for (std::size_t pos = 0; pos < std::size(num); pos++)
        {
            while (!st.empty() && st.back() > num[pos] && k > 0)
            {
                st.pop_back();
                k--;
            }
            
            if (st.empty() && num[pos] == '0')
            {
                continue;
            }
            
            st.push_back(num[pos]);
        }
        
        while (!st.empty() && k > 0)
        {
            st.pop_back();
            k--;
        }
        
        return st.empty() ? "0" : std::string(std::begin(st), std::end(st));
    }
};
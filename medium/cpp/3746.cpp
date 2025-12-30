// https://leetcode.com/problems/minimum-string-length-after-balanced-removals/description/

class Solution
{
public:
    int minLengthAfterRemovals(const std::string& s)
    {
        const int n = std::size(s);

        std::vector<char> st;
        st.reserve(n);

        for (int i = 0; i < n; i++)
        {
            if (st.empty() || st.back() == s[i])
            {
                st.push_back(s[i]);
            }
            else
            {
                st.pop_back();
            }
        }

        return st.size();
    }
};
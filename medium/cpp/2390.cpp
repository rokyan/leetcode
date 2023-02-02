// https://leetcode.com/problems/removing-stars-from-a-string/description/

class Solution
{
public:
    std::string removeStars(std::string s)
    {
        std::vector<char> st;

        for (auto c : s)
        {
            if (c == '*' && !st.empty())
            {
                st.pop_back();
            }
            else
            {
                st.push_back(c);
            }
        }

        return std::string(std::begin(st), std::end(st));
    }
};
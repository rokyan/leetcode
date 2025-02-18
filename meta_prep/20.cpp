class Solution
{
public:
    bool isValid(const std::string& s)
    {
        std::unordered_map<char, char> mapping
        {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        std::vector<char> st;

        for (auto c : s)
        {
            if (const auto it = mapping.find(c); it != std::end(mapping))
            {
                if (st.empty() || st.back() != it->second)
                {
                    return false;
                }
                else
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back(c);
            }
        }

        return st.empty();
    }
};
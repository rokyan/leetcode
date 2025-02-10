class Solution
{
public:
    std::string minRemoveToMakeValid(const std::string& s)
    {
        const auto n = std::size(s);

        std::vector<int> st;
        st.reserve(n);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push_back(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && s[st.back()] == '(')
                {
                    st.pop_back();
                }
                else
                {
                    st.push_back(i);
                }
            }
        }

        std::string res;
        res.reserve(n);

        for (auto i = 0, j = 0; i < n; i++)
        {
            while (j < std::size(st) && st[j] < i)
            {
                j++;
            }

            if (j < std::size(st) && st[j] == i)
            {
                continue;
            }

            res.push_back(s[i]);
        }

        return res;
    }
};
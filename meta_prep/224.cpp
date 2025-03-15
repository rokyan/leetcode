class Solution
{
public:
    int calculate(const std::string& s)
    {
        std::vector<int> st;
        auto num = 0LL;
        auto mult = 1LL;
        auto res = 0LL;

        for (auto c : s)
        {
            if (std::isdigit(c))
            {
                num = 10 * num + c - '0';
            }
            else if (c == '+')
            {
                res += mult * num;
                mult = 1;
                num = 0;
            }
            else if (c == '-')
            {
                res += mult * num;
                mult = -1;
                num = 0;
            }
            else if (c == '(')
            {
                st.push_back(res);
                st.push_back(mult);
                mult = 1;
                res = 0;
            }
            else if (c == ')')
            {
                res += mult * num;
                res *= st.back();
                st.pop_back();
                res += st.back();
                st.pop_back();
                num = 0;
                mult = 1;
            }
        }

        res += mult * num;
        return res;
    }
};
// https://leetcode.com/problems/basic-calculator-ii/description/

class Solution
{
public:
    int calculate(std::string s)
    {
        std::vector<long long> st;
        st.push_back(0);

        auto cur = 0LL;

        auto op = '+';

        for (auto c : s)
        {
            if (c == ' ')
            {
                continue;
            }

            if (c >= '0' && c <= '9')
            {
                cur = 10 * cur + c - '0';
            }
            else
            {
                if (op == '+' || op == '-')
                {
                    st.push_back(op == '+' ? cur : -cur);
                }
                else
                {
                    auto last = st.back();
                    st.pop_back();
                    st.push_back(op == '*' ? last * cur : last / cur);
                }
 
                op = c;
                cur = 0;
            }
        }

        if (op == '+' || op == '-')
        {
            st.push_back(op == '+' ? cur : -cur);
        }
        else
        {
            auto last = st.back();
            st.pop_back();
            st.push_back(op == '*' ? last * cur : last / cur);
        }

        return std::accumulate(std::cbegin(st), std::cend(st), 0LL);
    }
};
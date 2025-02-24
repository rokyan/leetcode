class Solution
{
public:
    int calculate(const std::string& s)
    {
        std::vector<long long> st;
        auto last_op = '+';
        auto cur = 0LL;

        auto update = [&st, &last_op, &cur]()
        {
            if (last_op == '+' || last_op == '-')
            {
                const auto updated = cur * (last_op == '+' ? 1 : -1);
                st.push_back(updated);
            }
            else
            {
                const auto last = st.back();
                st.pop_back();
                const auto updated = last_op == '*' ? last * cur : last / cur;
                st.push_back(updated);
            }
        };

        for (auto c : s)
        {
            if (c == ' ')
            {

            }
            else if (c >= '0' && c <= '9')
            {
                cur = 10 * cur + c - '0';
            }
            else
            {
                update();
                cur = 0;
                last_op = c;
            } 
        }

        update();

        return std::accumulate(std::cbegin(st), std::cend(st), 0LL);
    }
};
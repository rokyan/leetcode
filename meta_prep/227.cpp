class Solution
{
public:
    int calculate(const std::string& s)
    {
        auto last_op = '+';
        auto res = 0LL;
        auto prev = 0LL;
        auto cur = 0LL;

        auto update = [&last_op, &res, &prev, &cur]()
        {
            if (last_op == '+' || last_op == '-')
            {
                if (last_op == '-')
                {
                    cur *= -1;
                }

                res += cur;
                prev = cur;
            }
            else
            {
                res -= prev;
                
                if (last_op == '*')
                {
                    prev *= cur;
                }
                else
                {
                    prev /= cur;
                }

                res += prev;
            }
        };

        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
            {
                cur = 10 * cur + c - '0';
            }
            else if (c != ' ')
            {
                update();
                cur = 0;
                last_op = c;
            } 
        }

        update();

        return res;
    }
};
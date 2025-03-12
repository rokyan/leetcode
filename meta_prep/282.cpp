class Solution
{
private:
    static constexpr auto ops = {'+', '-', '*'};

public:
    std::vector<std::string> addOperators(const std::string& num, int target)
    {
        std::string expr;
        solve(num, 0, expr, target);
        return exprs;
    }

private:
    void solve(const std::string& num, std::size_t pos,
        std::string& expr, int target,
        long long cur = 0, long long prev = 0, char prev_op = '+', long long res = 0)
    {
        if (pos == std::size(num))
        {
            if (prev_op == '+')
            {
                res += cur;
            }
            else if (prev_op == '-')
            {
                res -= cur;
            }
            else
            {
                res += -prev + prev * cur;
            }

            if (res == target)
            {
                exprs.push_back(expr);
            }

            return;
        }

        if (!expr.empty() && std::isdigit(expr.back()))
        {
            for (auto op : ops)
            {
                expr.push_back(op);

                if (prev_op == '+')
                {
                    solve(num, pos, expr, target, 0, cur, op, res + cur);
                }
                else if (prev_op == '-')
                {
                    solve(num, pos, expr, target, 0, -cur, op, res - cur);
                }
                else
                {
                    solve(num, pos, expr, target, 0, prev * cur, op, res - prev + prev * cur);
                }

                expr.pop_back();
            }
        }

        if (!expr.empty() && expr.back() == '0' && cur == 0)
        {
            return;
        }

        expr.push_back(num[pos]);
        solve(num, pos + 1, expr, target, cur * 10 + num[pos] - '0', prev, prev_op, res);
        expr.pop_back();
    }

private:
    std::vector<std::string> exprs;
};
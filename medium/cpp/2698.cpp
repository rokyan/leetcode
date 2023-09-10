// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/

class Solution
{
public:
    int punishmentNumber(int n)
    {
        auto res = 0;

        for (auto i = 1; i <= n; i++)
        {
            if (check(i * i, i))
            {
                res += i * i;
            }
        }

        return res;
    }

private:
    bool check(int x, int init, int acc = 0, int sum = 0, int p = 1)
    {
        if (x == 0)
        {
            sum += acc;
            return sum == init;
        }

        const auto d = x % 10;

        return check(x / 10, init, d * p + acc, sum, p * 10) || check(x / 10, init, d * p, sum + acc, 1);
    }
};
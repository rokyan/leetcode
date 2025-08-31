// https://leetcode.com/problems/smallest-greater-multiple-made-of-two-digits/description/

class Solution
{
private:
    static constexpr auto lim = (1ULL << 31) - 1;

public:
    int findInteger(int k, int digit1, int digit2)
    {
        solve(0, k, digit1, digit2);
        return res;
    }

private:
    void solve(long long cur, int k, int digit1, int digit2)
    {
        if (cur % k == 0 && cur > k)
        {
            res = res == -1 ? cur : std::min(res, cur);
            return;
        }

        auto next = 10 * cur + digit1;

        if (next != 0 && next <= lim)
        {
            solve(next, k, digit1, digit2);
        }

        next = 10 * cur + digit2;

        if (next != 0 && next <= lim)
        {
            solve(next, k, digit1, digit2);
        }
    }

private:
    long long res = -1;
};
// https://leetcode.com/problems/number-of-self-divisible-permutations/description/

class Solution
{
public:
    int selfDivisiblePermutationCount(int n)
    {
        std::vector<char> used(n);

        generate(1, n, used);

        return res;
    }

private:
    void generate(int pos, int n, std::vector<char>& used)
    {
        if (pos == n + 1)
        {
            res++;
            return;
        }

        for (auto next = 1; next <= n; next++)
        {
            if (!used[next - 1] && gcd(pos, next) == 1)
            {
                used[next - 1] = true;
                generate(pos + 1, n, used);
                used[next - 1] = false;
            }
        }
    }

    int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }

private:
    int res = 0;
};
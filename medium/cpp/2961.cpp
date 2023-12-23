// https://leetcode.com/problems/double-modular-exponentiation/

class Solution
{
public:
    std::vector<int> getGoodIndices(std::vector<std::vector<int>>& variables, int target)
    {
        std::vector<int> res;
        res.reserve(std::size(variables));

        for (auto i = 0; i < std::size(variables); i++)
        {
            const auto& v = variables[i];
            const auto a = v[0];
            const auto b = v[1];
            const auto c = v[2];
            const auto m = v[3];

            if (pow(pow(a, b, 10), c, m) == target)
            {
                res.push_back(i);
            }
        }

        return res;
    }

private:
    int pow(int x, int n, int m)
    {
        if (n == 1)
        {
            return x % m;
        }

        if (n % 2 == 0)
        {
            return pow(x * x % m, n / 2, m) % m;
        }
        else
        {
            return x * pow(x, n - 1, m) % m;
        }
    }
};
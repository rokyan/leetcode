// https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/

class Solution
{
public:
    int minIncrements(int n, std::vector<int>& cost)
    {
        auto res = 0;

        solve(1, n, cost, res);

        return res;
    }

private:
    int solve(int v, int n, const std::vector<int>& cost, int& res)
    {
        if (2 * v >= n)
        {
            return cost[v - 1];
        }

        const auto lv = solve(2 * v, n, cost, res);
        const auto rv = solve(2 * v + 1, n, cost, res);

        res += std::abs(lv - rv);

        return cost[v - 1] + std::max(lv, rv);
    }
};
// https://leetcode.com/problems/find-missing-observations/description/

class Solution
{
public:
    std::vector<int> missingRolls(const std::vector<int>& rolls, int mean, int n)
    {
        const auto sum = std::accumulate(std::cbegin(rolls), std::cend(rolls), 0);
        const auto m = std::size(rolls);
        const auto expected = mean * (m + n) - sum;

        if (expected < n || expected > 6 * n)
        {
            return {};
        }

        const auto avg = expected / n;

        std::vector<int> res(n, avg);

        auto rem = expected - avg * n;

        for (auto i = 0; i < n && rem; i++, rem--)
        {
            res[i]++;
        }

        return res;
    }
};
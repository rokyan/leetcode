// https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/description/

class Solution
{
public:
    long long minCost(int n, int m, const std::vector<std::vector<int>>& waitCost)
    {
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(m,-1));
        dp[0][0] = 1;

        const auto update = [](long long& value, long long newValue)
        {
            if (value == -1)
            {
                value = newValue;
                return;
            }

            value = std::min(value, newValue);
        };

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                const auto cost = (i + 1) * (j + 1);

                if (i > 0)
                {
                    update(dp[i][j], dp[i - 1][j] + waitCost[i][j] + cost);
                }

                if (j > 0)
                {
                    update(dp[i][j], dp[i][j - 1] + waitCost[i][j] + cost);
                }
            }
        }

        return dp[n - 1][m - 1] - waitCost[n - 1][m - 1];
    }
};
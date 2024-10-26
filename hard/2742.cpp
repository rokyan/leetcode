// https://leetcode.com/problems/painting-the-walls/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000 + 7;

public:
    int paintWalls(const std::vector<int>& cost, const std::vector<int>& time)
    {
        const auto n = static_cast<int>(std::size(cost));

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, inf));
        dp[0][0] = 0;

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (time[i - 1] + 1 >= j)
                {
                    dp[i][j] = std::min(dp[i][j], cost[i - 1]);
                }
                else if (time[i - 1] + 1 < j)
                {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - time[i - 1] - 1] + cost[i - 1]);
                }
            }
        }

        return dp[n][n];
    }
};
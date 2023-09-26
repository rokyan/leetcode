class Solution
{
private:
    static constexpr auto mod = 1000000007;

public:
    int waysToReachTarget(int target, std::vector<std::vector<int>>& types)
    {
        const auto n = std::size(types);

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1));
        dp[0][0] = 1;

        for (auto i = 1; i <= n; i++)
        {
            dp[i][0] = 1;

            for (auto j = 1; j <= target; j++)
            {
                for (auto k = 0; k <= types[i - 1][0]; k++)
                {
                    if (k * types[i - 1][1] > j)
                    {
                        break;
                    }

                    dp[i][j] += dp[i - 1][j - k * types[i - 1][1]];
                    dp[i][j] %= mod;
                }
            }
        }

        return dp[n][target];
    }
};
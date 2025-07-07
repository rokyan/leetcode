// https://leetcode.com/problems/inverse-coin-change/description/

class Solution
{
public:
    std::vector<int> findCoins(const std::vector<int>& numWays)
    {
        const auto n = std::size(numWays);

        std::vector<int> coins;
        coins.reserve(n);

        for (auto i = 0; i < n; i++)
        {
            const auto ways = calc(i + 1, coins);

            if (ways == numWays[i])
            {

            }
            else if (ways + 1 == numWays[i])
            {
                coins.push_back(i + 1);
            }
            else
            {
                return {};
            }
        }

        return coins;
    }

private:
    int calc(int value, const std::vector<int>& coins)
    {
        const auto n = std::size(coins);

        if (n == 0)
        {
            return 0;
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(value + 1, -1));
        std::fill(std::begin(dp[0]), std::end(dp[0]), 0);

        for (auto i = 1; i <= n; i++)
        {
            dp[i][0] = 1;

            for (auto v = 1; v <= value; v++)
            {
                if (i > 0)
                {
                    dp[i][v] = dp[i - 1][v];
                }

                if (v >= coins[i - 1] && dp[i][v - coins[i - 1]] != -1)
                {
                    dp[i][v] += dp[i][v - coins[i - 1]];
                }
            }
        }

        return dp[n][value] == -1 ? 0 : dp[n][value];
    }
};
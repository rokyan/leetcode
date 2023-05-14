// https://leetcode.com/problems/coin-change/description/

class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        std::vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (auto cur = 1; cur <= amount; cur++)
        {
            for (auto coin : coins)
            {
                if (cur >= coin && dp[cur - coin] > -1)
                {
                    dp[cur] = (dp[cur] == -1) ? 1 + dp[cur - coin] : std::min(dp[cur], 1 + dp[cur - coin]);
                }
            }
        }

        return dp.back();
    }
};
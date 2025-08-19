// https://leetcode.com/problems/maximum-total-reward-using-operations-i/description/

class Solution
{
public:
    int maxTotalReward(std::vector<int>& rewardValues)
    {
        std::ranges::sort(rewardValues);

        const auto n = std::size(rewardValues);

        std::vector<std::vector<char>> dp(n + 1, std::vector<char>(4000 + 4, false));
        dp[0][0] = true;

        auto res = 0;

        for (auto i = 1; i <= n; i++)
        {
            const auto value = rewardValues[i - 1];

            for (auto prevValue = 0; prevValue < 4000 + 4; prevValue++)
            {
                dp[i][prevValue] = dp[i - 1][prevValue];
            }

            for (auto prevValue = 0; prevValue < value; prevValue++)
            {
                if (dp[i - 1][prevValue])
                {
                    dp[i][prevValue + value] = true;
                    res = std::max(res, prevValue + value);
                }
            }
        }

        return res;
    }
};
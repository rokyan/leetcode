// https://leetcode.com/problems/maximum-points-tourist-can-earn/description/

class Solution
{
public:
    int maxScore(int n, int k,
        const std::vector<std::vector<int>>& stayScore,
        const std::vector<std::vector<int>>& travelScore)
    {
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n));

        for (auto day = 1; day <= k; day++)
        {
            for (auto v = 0; v < n; v++)
            {
                dp[day][v] = stayScore[day - 1][v] + dp[day - 1][v];

                for (auto prev = 0; prev < n; prev++)
                {
                    dp[day][v] = std::max(dp[day][v], dp[day - 1][prev] + travelScore[prev][v]);
                }
            }
        }

        return *std::max_element(std::cbegin(dp[k]), std::cend(dp[k]));
    }
};
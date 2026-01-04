// https://leetcode.com/problems/maximum-weight-in-two-bags/description/

class Solution
{
public:
    int maxWeight(const std::vector<int>& weights, int w1, int w2)
    {
        const int n = weights.size();

        std::vector<std::vector<std::vector<int>>> dp(n + 1,
            std::vector<std::vector<int>>(w1 + 1, std::vector<int>(w2 + 1)));

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            const int weight = weights[i - 1];

            for (int j = 0; j <= w1; j++)
            {
                for (int k = 0; k <= w2; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];

                    if (j > 0)
                    {
                        dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k]);
                    }

                    if (k > 0)
                    {
                        dp[i][j][k] = std::max(dp[i][j][k], dp[i][j][k - 1]);
                    }

                    if (j >= weight)
                    {
                        dp[i][j][k] = std::max(dp[i][j][k], weight + dp[i - 1][j - weight][k]);
                    }

                    if (k >= weight)
                    {
                        dp[i][j][k] = std::max(dp[i][j][k], weight + dp[i - 1][j][k - weight]);
                    }

                    res = std::max(res, dp[i][j][k]);
                }
            }
        }

        return res;
    }
};
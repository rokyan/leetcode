// https://leetcode.com/problems/paint-fence/description/

class Solution
{
public:
    int numWays(int n, int k)
    {
        if (n == 1)
        {
            return k;
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(k));

        for (auto i = 0; i < k; i++)
        {
            dp[0][i] = 1;
            dp[1][i] = k;
        }

        for (auto i = 2; i < n; i++)
        {
            for (auto j = 0; j < k; j++)
            {
                dp[i][j] += (k - 1) * (dp[i - 1][j] + dp[i - 2][j]);
            }
        }

        auto res = 0;

        for (auto i = 0; i < k; i++)
        {
            res += dp.back()[i];
        }

        return res;
    }
};
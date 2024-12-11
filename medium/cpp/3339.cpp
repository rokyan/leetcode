// https://leetcode.com/problems/find-the-number-of-k-even-arrays/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countOfArrays(int n, int m, int k)
    {
        std::vector<std::vector<std::vector<int>>> dp(n,
            std::vector<std::vector<int>>(k + 1, std::vector<int>(2)));

        dp[0][0][0] = m / 2;
        dp[0][0][1] = m - m / 2;

        for (auto i = 0; i < n; i++)
        {
            if (i > 0)
            {
                for (auto t = 0; t <= k; t++)
                {
                    dp[i][t][0] = 1LL * m / 2 * dp[i - 1][t][1] % mod;
                    if (t > 0) dp[i][t][0] += 1LL * m / 2 * dp[i - 1][t - 1][0] % mod;
                    dp[i][t][0] %= mod;
                    dp[i][t][1] = 1LL * (m - m / 2) * dp[i - 1][t][0] % mod;
                    dp[i][t][1] += 1LL * (m - m / 2) * dp[i - 1][t][1] % mod;
                    dp[i][t][1] %= mod;
                }
            }
        }

        return (dp[n - 1][k][0] + dp[n - 1][k][1]) % mod;
    }
};
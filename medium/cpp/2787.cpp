// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int numberOfWays(int n, int x)
    {
        std::vector<int> pows;

        auto cur = 1;
        auto p = pow(cur, x);

        while (p <= n)
        {
            pows.push_back(p);
            p = pow(++cur, x);
        }

        const auto m = std::size(pows);

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1));
        dp[0][0] = 1;

        for (auto i = 1; i <= m; i++)
        {
            for (auto j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (pows[i - 1] <= j && dp[i - 1][j - pows[i - 1]] != -1)
                {
                    dp[i][j] = dp[i][j] == -1
                        ? dp[i - 1][j - pows[i - 1]]
                        : (dp[i][j] + dp[i - 1][j - pows[i - 1]]) % mod;
                }
            }
        }

        return dp[m][n] == -1 ? 0 : dp[m][n];
    }

private:
    int pow(int x, int p)
    {
        auto res = 1;

        while (p--)
        {
            res *= x;
        }

        return res;
    }
};
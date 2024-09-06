// https://leetcode.com/problems/the-number-of-ways-to-make-the-sum/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int numberOfWays(int n)
    {
        std::array<int, 3> vals{ 1, 2, 6 };

        std::vector<std::vector<int>> dp(3, std::vector<int>(n + 1));

        for (auto i = 0; i < 3; i++)
        {
            for (auto j = 1; j <= n; j++)
            {
                if (i > 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }

                if (j == vals[i])
                {
                    dp[i][j]++;
                }
                else if (j > vals[i])
                {
                    dp[i][j] += dp[i][j - vals[i]];
                }

                dp[i][j] %= mod;
            }
        }

        auto res = dp[2].back();

        if (n == 4)
        {
            res++;
            res %= mod;
        }
        else if (n > 4)
        {
            res += dp[2][n - 4];
            res %= mod;
        }

        if (n == 8)
        {
            res++;
            res %= mod;
        }
        else if (n > 8)
        {
            res += dp[2][n - 8];
            res %= mod;
        }

        return res;
    }
};
class Solution
{
private:
    static constexpr auto MOD = 1000 * 1000 * 1000 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        std::vector<int> dp(high + 1);
        dp[0] = 1;

        auto res = 0;

        for (auto i = 0; i <= high; i++)
        {
            if (i + zero <= high)
            {
                dp[i + zero] += dp[i];
                dp[i + zero] %= MOD;
            }

            if (i + one <= high)
            {
                dp[i + one] += dp[i];
                dp[i + one] %= MOD;
            }

            if (i >= low)
            {
                res += dp[i];
                res %= MOD;
            }
        }

        return res;
    }
};
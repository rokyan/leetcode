// https://leetcode.com/problems/number-of-good-binary-strings/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup)
    {
        const auto n = maxLength;

        std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1));
        dp[0][0] = 1;

        auto res = 0;

        for (auto i = 1; i <= n; i++)
        {
            if (i >= zeroGroup)
            {
                dp[0][i] = (dp[0][i - zeroGroup] + dp[1][i - zeroGroup]) % mod;
            }

            if (i >= oneGroup)
            {
                dp[1][i] = (dp[0][i - oneGroup] + dp[1][i - oneGroup]) % mod;
            }

            if (i >= minLength)
            {
                for (auto d = 0; d < 2; d++)
                {
                    res += dp[d][i];
                    res %= mod;
                }
            }
        }

        return res;
    }
};
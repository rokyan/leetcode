// https://leetcode.com/problems/decode-ways-ii/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'007;

public:
    int numDecodings(const std::string& s)
    {
        const int len = std::size(s);

        std::vector<int> dp(len + 1);
        dp[0] = 1;

        for (int i = 1; i <= len; i++)
        {
            if (s[i - 1] == '*')
            {
                dp[i] = 9LL * dp[i - 1] % mod;

                if (i > 1)
                {
                    const char prev = s[i - 2];

                    if (prev == '*')
                    {
                        dp[i] += 15LL * dp[i - 2] % mod;
                        dp[i] %= mod;
                    }
                    else
                    {
                        if (prev != '0')
                        {
                            for (int d = 1; d <= 9; d++)
                            {
                                const int num = 10 * (prev - '0') + d;

                                if (num >= 1 && num <= 26)
                                {
                                    dp[i] += dp[i - 2];
                                    dp[i] %= mod;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (s[i - 1] != '0')
                {
                    dp[i] = dp[i - 1];
                    dp[i] %= mod;
                }

                if (i > 1)
                {
                    const char prev = s[i - 2];

                    if (prev == '*')
                    {
                        for (int d = 1; d <= 2; d++)
                        {
                            const int num = 10 * d + s[i - 1] - '0';

                            if (num >= 1 && num <= 26)
                            {
                                dp[i] += dp[i - 2];
                                dp[i] %= mod;
                            }
                        }
                    }
                    else
                    {
                        if (prev != '0')
                        {
                            const int num = 10 * (prev - '0') + s[i - 1] - '0';

                            if (num >= 1 && num <= 26)
                            {
                                dp[i] += dp[i - 2];
                                dp[i] %= mod;
                            }
                        }
                    }
                }
            }
        }

        return dp.back();
    }
};
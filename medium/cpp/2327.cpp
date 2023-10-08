// https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        std::vector<int> dp(n);
        dp[0] = 1;

        for (auto i = 1; i < n; i++)
        {
            for (auto j = delay; j < forget && i - j >= 0; j++)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }

        auto res = 0;

        for (auto i = 0; i < forget && i < n; i++)
        {
            res += dp[n - i - 1];
            res %= mod;
        }

        return res;
    }
};
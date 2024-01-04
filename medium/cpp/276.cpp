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

        std::vector<int> dp(n);

        for (auto i = 0; i < k; i++)
        {
            dp[0] = k;
            dp[1] = k * k;
        }

        for (auto i = 2; i < n; i++)
        {
            dp[i] += (k - 1) * (dp[i - 1] + dp[i - 2]);

        }

        return dp.back();
    }
};
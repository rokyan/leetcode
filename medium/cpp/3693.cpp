// https://leetcode.com/problems/climbing-stairs-ii/description/

class Solution
{
public:
    int climbStairs(int n, const std::vector<int>& costs)
    {
        std::vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int d = 1; d <= 3; d++)
            {
                const int prev = i - d;

                if (prev >= 0)
                {
                    dp[i] = std::min(dp[i], dp[prev] + d * d + costs[i - 1]);
                }
            }
        }

        return dp.back();
    }
};
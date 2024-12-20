// https://leetcode.com/problems/minimum-subarrays-in-a-valid-split/description/

class Solution
{
public:
    int validSubarraySplit(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= i; j++)
            {
                if (dp[j - 1] != -1 && gcd(nums[i - 1], nums[j - 1]) > 1)
                {
                    dp[i] = dp[i] == -1 ? 1 + dp[j - 1] : std::min(dp[i], 1 + dp[j - 1]);
                }
            }
        }

        return dp.back();
    }

private:
    int gcd(int x, int y)
    {
        return x == 0 ? y : gcd(y % x, x);
    }
};
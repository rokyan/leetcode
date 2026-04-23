// https://leetcode.com/problems/minimum-removals-to-achieve-target-xor/description/

class Solution
{
public:
    int minRemovals(const std::vector<int>& nums, int target)
    {
        const int n = nums.size();

        const int maxVal = 1024 * 16;

        std::vector<std::vector<int>> dp(n, std::vector<int>(maxVal, -1));
        dp[0][0] = 0;
        dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int val = 0; val < maxVal; val++)
            {
                dp[i][val] = dp[i - 1][val];
            }

            dp[i][nums[i]] = std::max(1, dp[i][nums[i]]);

            for (int val = 0; val < maxVal; val++)
            {
                if (dp[i - 1][val ^ nums[i]] != -1)
                {
                    dp[i][val] = std::max(dp[i][val], dp[i - 1][val ^ nums[i]] + 1);
                }
            }
        }

        return dp[n - 1][target] == -1 ? -1 : n - dp[n - 1][target];
    }
};
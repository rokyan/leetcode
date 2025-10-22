// https://leetcode.com/problems/minimum-operations-to-make-the-array-beautiful/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums)
    {
        const int n = std::size(nums);
        const int maxVal = 100;

        std::vector<std::vector<int>> dp(n,
            std::vector<int>(maxVal + 1, -1));
        dp[0][nums[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = nums[i]; j <= maxVal; j++)
            {
                int cost = j - nums[i];

                for (int k = 1; k <= j; k++)
                {
                    if (dp[i - 1][k] != -1 && j % k == 0)
                    {
                        int totalCost = cost + dp[i - 1][k];

                        if (dp[i][j] == -1)
                        {
                            dp[i][j] = totalCost;
                        }
                        else
                        {
                            dp[i][j] = std::min(dp[i][j], totalCost);
                        }
                    }
                }
            }
        }

        int res = -1;

        for (int i = 1; i <= maxVal; i++)
        {
            if (dp[n - 1][i] != -1)
            {
                if (res == -1)
                {
                    res = dp[n - 1][i];
                }
                else
                {
                    res = std::min(res, dp[n - 1][i]);
                }
            }
        }

        return res;
    }
};
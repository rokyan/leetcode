// https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/

class Solution
{
public:
    int lengthOfLongestSubsequence(std::vector<int>& nums, int target)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<int>> dp(n, std::vector<int>(target + 1));

        auto res = -1;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j <= target; j++)
            {
                if (i > 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }

                if (nums[i] == j)
                {
                    dp[i][j] = std::max(dp[i][j], 1);
                }
                else if (nums[i] < j && i > 0 && dp[i - 1][j - nums[i]])
                {
                    dp[i][j] = std::max(dp[i][j], 1 + dp[i - 1][j - nums[i]]);
                }
            }

            if (dp[i][target])
            {
                res = std::max(res, dp[i][target]);
            }
        }

        return res;
    }
};
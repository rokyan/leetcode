// https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/description/

class Solution
{
public:
    int maximumLength(const std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, 1));

        auto res = 1;

        for (auto d = 0; d <= k; d++)
        {
            for (auto i = 0; i < n; i++)
            {
                for (auto j = 0; j < i; j++)
                {
                    if (nums[i] == nums[j])
                    {
                        dp[d][i] = std::max(dp[d][i], dp[d][j] + 1);
                    }

                    if (d > 0)
                    {
                        dp[d][i] = std::max(dp[d][i], dp[d - 1][j] + 1);
                    }

                    res = std::max(res, dp[d][i]);
                }
            }
        }

        return res;
    }
};
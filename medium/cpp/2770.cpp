// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/

class Solution
{
public:
    int maximumJumps(std::vector<int>& nums, int target)
    {
        const auto n = std::size(nums);
        std::vector<int> dp(n, -1);
        dp[0] = 0;

        for (auto j = 1; j < n; j++)
        {
            for (auto i = 0; i < j; i++)
            {
                if (dp[i] > -1 && std::abs(nums[j] - nums[i]) <= target)
                {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp.back();
    }
};
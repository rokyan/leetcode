// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

class Solution
{
public:
    bool validPartition(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n + 1);
        dp[0] = 1;

        for (auto i = 2; i <= n; i++)
        {
            if (nums[i - 1] == nums[i - 2])
            {
                dp[i] |= dp[i - 2];
            }

            if (i > 2 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3])
            {
                dp[i] |= dp[i - 3];
            }

            if (i > 2 && nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1)
            {
                dp[i] |= dp[i - 3];
            }
        }

        return dp.back();
    }
};
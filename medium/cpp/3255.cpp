// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/description/

class Solution
{
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n);

        for (auto i = 0; i < n; i++)
        {
            dp[i] = 1;

            if (i > 0 && nums[i] == nums[i - 1] + 1)
            {
                dp[i] = dp[i - 1] + 1;
            }
        }

        std::vector<int> res(n - k + 1, -1);

        for (auto i = 0; i + k - 1 < n; i++)
        {
            if (dp[i + k - 1] >= k)
            {
                res[i] = nums[i + k - 1];
            }
        }

        return res;
    }
};
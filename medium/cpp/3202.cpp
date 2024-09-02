// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/

class Solution
{
public:
    int maximumLength(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<int>> dp(n, std::vector<int>(k));

        auto res = 0;

        for (auto i = 1; i < n; i++)
        {
            for (auto j = 0; j < i; j++)
            {
                const auto rem = (nums[j] + nums[i]) % k;
                dp[i][rem] = std::max(dp[i][rem], dp[j][rem] + 1);
                res = std::max(res, dp[i][rem]);
            }
        }

        return res + 1;
    }
};
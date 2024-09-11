// https://leetcode.com/problems/maximum-alternating-subarray-sum/description/

class Solution
{
public:
    long long maximumAlternatingSubarraySum(const std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<long long> dp(2);

        auto res = static_cast<long long>(nums.back());

        for (auto i = n - 1; i >= 0; i--)
        {
            std::vector<long long> ndp(2);

            ndp[0] = nums[i] + std::max(0LL, dp[1]);
            ndp[1] = -nums[i] + std::max(0LL, dp[0]);

            dp = std::move(ndp);

            res = std::max(res, dp[0]);
        }

        return res;
    }
};
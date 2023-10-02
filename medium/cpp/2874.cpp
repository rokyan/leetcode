// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/

class Solution
{
public:
    long long maximumTripletValue(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n);

        auto msf = nums[0];

        for (auto i = 1; i < n; i++)
        {
            dp[i] = msf - nums[i];

            if (i > 1)
            {
                dp[i] = std::max(dp[i], dp[i - 1]);
            }

            msf = std::max(msf, nums[i]);
        }

        auto res = 0LL;

        msf = dp[1];

        for (auto i = 2; i < n; i++)
        {
            res = std::max(res, 1LL * msf * nums[i]);

            msf = std::max(msf, dp[i]);
        }

        return res;
    }
};
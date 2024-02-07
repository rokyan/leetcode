// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

class Solution
{
public:
    int maxNonOverlapping(std::vector<int>& nums, int target)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n);

        std::unordered_map<int, int> pref;
        pref[0] = -1;

        for (auto i = 0, s = 0; i < n; i++)
        {
            s += nums[i];

            if (i > 0)
            {
                dp[i] = dp[i - 1];
            }

            if (const auto it = pref.find(s - target); it != std::end(pref))
            {
                const auto pos = it->second;

                dp[i] = std::max(dp[i], 1 + (pos == -1 ? 0 : dp[pos]));
            }

            pref[s] = i;
        }

        return dp.back();
    }
};
// https://leetcode.com/problems/minimum-sum-after-divisible-sum-deletions/description/

class Solution
{
public:
    long long minArraySum(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> pos;
        pos[0] = -1;

        const auto n = std::size(nums);

        std::vector<long long> dp(n);

        auto sum = 0LL;

        for (auto i = 0; i < n; i++)
        {
            sum += nums[i];

            dp[i] = nums[i] + (i > 0 ? dp[i - 1] : 0);

            if (const auto it = pos.find(sum % k); it != std::cend(pos))
            {
                dp[i] = std::min(dp[i], (it->second >= 0 ? dp[it->second] : 0));
            }
            
            pos[sum % k] = i;
        }

        return dp.back();
    }
};
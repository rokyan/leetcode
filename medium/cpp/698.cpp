// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

class Solution
{
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k)
    {
        const auto sum = std::accumulate(std::begin(nums), std::end(nums), 0, [](auto acc, auto e) {
            return acc + e;
        });

        if (sum % k != 0)
        {
            return false;
        }

        const auto target = sum / k;

        const auto n = std::size(nums);

        std::vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (auto mask = 0; mask < (1 << n); mask++)
        {
            if (dp[mask] != -1)
            {
                for (auto bit = 0; bit < n; bit++)
                {
                    if (!(mask & (1 << bit)))
                    {
                        const auto next = mask | (1 << bit);

                        if (dp[mask] + nums[bit] <= target)
                        {
                            dp[next] = (dp[mask] + nums[bit]) % target;
                        }
                    }
                }
            }
        }

        return (dp[(1 << n) - 1]) == 0;
    }
};
// https://leetcode.com/problems/constrained-subsequence-sum/

class Solution
{
public:
    int constrainedSubsetSum(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n);
        dp[0] = nums[0];

        std::multiset<int> s;
        s.insert(nums[0]);

        auto res = nums[0];

        for (auto i = 1; i < n; i++)
        {
            if (i > k)
            {
                s.erase(s.find(dp[i - k - 1]));
            }

            dp[i] = nums[i] + (*std::rbegin(s) > 0 ? *std::rbegin(s) : 0);

            s.insert(dp[i]);

            res = std::max(res, dp[i]);
        }

        return res;
    }
};
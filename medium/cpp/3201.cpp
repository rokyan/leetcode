// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/

class Solution
{
public:
    int maximumLength(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto res = 0;

        for (auto mod = 0; mod < 2; mod++)
        {
            std::vector<int> dp(2);

            for (auto i = 0; i < n; i++)
            {
                const auto last = (2 + mod - nums[i] % 2) % 2;
                dp[nums[i] % 2] = std::max(dp[nums[i] % 2], dp[last] + 1);
            }

            res = std::max(res, *std::max_element(std::cbegin(dp), std::cend(dp)));
        }

        return res;
    }
};
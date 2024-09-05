// https://leetcode.com/problems/special-array-ii/description/

class Solution
{
public:
    std::vector<bool> isArraySpecial(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n);
        dp[0] = 1;

        for (auto i = 1; i < n; i++)
        {
            dp[i] = 1;

            if ((nums[i - 1] ^ nums[i]) & 1)
            {
                dp[i] += dp[i - 1];
            }
        }

        std::vector<bool> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            const auto left = query[0];
            const auto right = query[1];

            const auto len = dp[right];

            res.push_back(len >= right - left + 1);
        }

        return res;
    }
};
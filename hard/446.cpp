// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/

class Solution
{
public:
    int numberOfArithmeticSlices(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<std::unordered_map<long long, int>> dp(n);

        auto res = 0;

        for (auto i = 1; i < n; i++)
        {
            for (auto j = 0; j < i; j++)
            {
                const auto d = 0LL + nums[i] - nums[j];

                if (const auto it = dp[j].find(d); it != std::end(dp[j]))
                {
                    dp[i][d] += it->second;
                    res += it->second;
                }

                dp[i][d]++;
            }

            std::cout << res << std::endl;
        }

        return res;
    }
};
// https://leetcode.com/problems/find-x-value-of-array-i/description/

class Solution
{
public:
    std::vector<long long> resultArray(const std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<int>> dp(n, std::vector<int>(k));
        std::vector<long long> res(k);

        for (auto i = 0; i < n; i++)
        {
            dp[i][nums[i] % k]++;

            if (i > 0)
            {
                for (auto j = 0; j < k; j++)
                {
                    dp[i][1LL * nums[i] * j % k] += dp[i - 1][j];
                }
            }

            for (auto j = 0; j < k; j++)
            {
                res[j] += dp[i][j];
            }
        }
 
        return res;
    }
};
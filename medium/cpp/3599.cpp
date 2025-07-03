// https://leetcode.com/problems/partition-array-to-minimize-xor/description/

class Solution
{
public:
    int minXor(const std::vector<int>& nums, int subarraysCount)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<int>> dp(subarraysCount + 1, std::vector<int>(n, -1));

        for (auto i = 0; i < n; i++)
        {
            dp[1][i] = nums[i] ^ (i > 0 ? dp[1][i - 1] : 0);
        }

        for (auto k = 2; k <= subarraysCount; k++)
        {
            for (auto i = 0; i < n; i++)
            {
                auto xorVal = 0;

                for (auto j = i; j > 0; j--)
                {
                    if (dp[k - 1][j - 1] == -1)
                    {
                        continue;
                    }
                    xorVal ^= nums[j];
                    const auto val = std::max(xorVal, dp[k - 1][j - 1]);
                    dp[k][i] = dp[k][i] == -1 ? val : std::min(dp[k][i], val);
                }
            }
        }

        return dp[subarraysCount][n - 1];
    }
};
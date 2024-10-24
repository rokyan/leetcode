// https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/description/

class Solution
{
private:
    static constexpr auto max_val = 50;
    static constexpr auto mod = 1'000'000'000 + 7;

public:
    int countOfPairs(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<std::vector<int>>>
            dp(n, std::vector<std::vector<int>>(max_val + 1, std::vector<int>(max_val + 1, -1)));

        for (auto i = 0; i <= nums[0]; i++)
        {
            dp[0][i][nums[0] - i] = 1;
        }

        for (auto k = 1; k < n; k++)
        {
            for (auto i = 0; i <= nums[k]; i++)
            {
                for (auto j = 0; j <= std::min(nums[k - 1], i); j++)
                {
                    if (dp[k - 1][j][nums[k - 1] - j] != -1 &&
                        nums[k - 1] - j >= nums[k] - i)
                    {
                        dp[k][i][nums[k] - i] = dp[k][i][nums[k] - i] == -1
                            ? dp[k - 1][j][nums[k - 1] - j]
                            : dp[k][i][nums[k] - i] + dp[k - 1][j][nums[k - 1] - j];
                        dp[k][i][nums[k] - i] %= mod;
                    }
                }
            }  
        }

        auto res = 0;

        for (auto i = 0; i <= nums[n - 1]; i++)
        {
            if (dp[n - 1][i][nums[n - 1] - i] != -1)
            {
                res += dp[n - 1][i][nums[n - 1] - i];
                res %= mod;
            }
        }

        return res;
    }
};
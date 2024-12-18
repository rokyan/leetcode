// https://leetcode.com/problems/minimum-array-sum/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int minArraySum(const std::vector<int>& nums, int dec, int op1, int op2)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<std::vector<int>>> dp(n,
            std::vector<std::vector<int>>(op1 + 1, std::vector<int>(op2 + 1, inf)));

        dp[0][0][0] = nums[0];
    
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j <= op1; j++)
            {
                for (auto k = 0; k <= op2; k++)
                {
                    if (i > 0)
                    {
                        dp[i][j][k] = dp[i - 1][j][k] + nums[i];
                    }

                    if (j > 0)
                    {
                        auto prev = i > 0 ? dp[i - 1][j - 1][k] : 0;
                        auto val = nums[i] / 2 + nums[i] % 2;

                        dp[i][j][k] = std::min(dp[i][j][k], val + prev);

                        if (k > 0 && val >= dec)
                        {
                            prev = i > 0 ? dp[i - 1][j - 1][k - 1] : 0;
                            val = val - dec;
                            dp[i][j][k] = std::min(dp[i][j][k], val + prev);
                        }
                    }

                    if (k > 0 && nums[i] >= dec)
                    {
                        auto prev = i > 0 ? dp[i - 1][j][k - 1] : 0;
                        auto val = nums[i] - dec;

                        dp[i][j][k] = std::min(dp[i][j][k], val + prev);

                        if (j > 0 && val > 0)
                        {
                            auto prev = i > 0 ? dp[i - 1][j - 1][k - 1] : 0;
                            val = val / 2 + val % 2;
                            dp[i][j][k] = std::min(dp[i][j][k], val + prev);
                        }
                    }
                }
            }
        }

        auto res = dp[n - 1][0][0];

        for (auto j = 0; j <= op1; j++)
        {
            for (auto k = 0; k <= op2; k++)
            {
                res = std::min(res, dp[n - 1][j][k]);
            }
        }

        return res;
    }
};
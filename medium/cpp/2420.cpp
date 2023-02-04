// https://leetcode.com/problems/find-all-good-indices/description/

class Solution
{
public:
    std::vector<int> goodIndices(std::vector<int>& nums, int k)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> dp(n);
        dp.back() = 1;

        for (auto i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= nums[i + 1])
            {
                dp[i] = 1 + dp[i + 1];
            }
            else
            {
                dp[i] = 1;
            }
        }

        auto acc = 1;

        std::vector<int> res;

        for (auto i = 1; i + 1 < n; i++)
        {
            if (acc >= k && dp[i + 1] >= k)
            {
                res.push_back(i);
            }

            if (nums[i] <= nums[i - 1])
            {
                acc++;
            }
            else
            {
                acc = 1;
            }
        }

        return res;
    }
};
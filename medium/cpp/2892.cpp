// https://leetcode.com/problems/minimizing-array-after-replacing-pairs-with-their-product/description/

class Solution
{
public:
    int minArrayLength(std::vector<int>& nums, int k)
    {
        if (std::ranges::find(nums, 0) != std::cend(nums))
        {
            return 1;
        }

        auto last = 0;

        auto n = std::size(nums);

        for (auto i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == 1 && nums[i - 1] == 1)
            {
                continue;
            }

            nums[last++] = nums[i];
        }

        n = last;

        std::vector<int> dp(n, 2 * n);
        dp[0] = 1;

        for (auto i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + 1;

            auto acc = 1LL;
            auto j = i;

            while (j >= 0 && acc * nums[j] <= k)
            {
                acc *= nums[j--];
            }

            if (j == -1)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }

        return dp.back();
    }
};
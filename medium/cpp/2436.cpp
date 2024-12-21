// https://leetcode.com/problems/minimum-split-into-subarrays-with-gcd-greater-than-one/description/

class Solution
{
public:
    int minimumSplits(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n, n + 1);
        dp[0] = 1;

        for (auto i = 1; i < n; i++)
        {
            auto j = static_cast<int>(i);
            auto val = nums[i];

            while (j >= 0 && (val = gcd(val, nums[j])) > 1)
            {
                dp[i] = std::min(dp[i], 1 + (j > 0 ? dp[j - 1] : 0));
                j--;
            }
        }

        return dp.back();
    }

private:
    int gcd(int x, int y)
    {
        return x == 0 ? y : gcd(y % x, x);
    }
};
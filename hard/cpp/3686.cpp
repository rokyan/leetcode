// https://leetcode.com/problems/number-of-stable-subsequences/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'000 + 7;

public:
    int countStableSubsequences(const std::vector<int>& nums)
    {
        int n = nums.size();

        std::vector<std::vector<int>> dp(2, std::vector<int>(2));

        int even = (nums[0] % 2 == 0);
        int odd = 1 - even;

        for (int i = 1; i < n; i++)
        {
            auto next = dp;

            for (int p1 = 0; p1 < 2; p1++)
            {
                for (int p2 = 0; p2 < 2; p2++)
                {
                    if (p1 == p2 && p2 == nums[i] % 2)
                    {
                        continue;
                    }

                    next[p2][nums[i] % 2] += dp[p1][p2];
                    next[p2][nums[i] % 2] %= mod;
                }
            }

            next[0][nums[i] % 2] += even;
            next[0][nums[i] % 2] %= mod;

            next[1][nums[i] % 2] += odd;
            next[1][nums[i] % 2] %= mod;

            even += nums[i] % 2 == 0;
            odd += nums[i] % 2 != 0;

            dp = std::move(next);
        }

        int res = n;

        for (int p1 = 0; p1 < 2; p1++)
        {
            for (int p2 = 0; p2 < 2; p2++)
            {
                res += dp[p1][p2];
                res %= mod;
            }
        }

        return res;
    }
};
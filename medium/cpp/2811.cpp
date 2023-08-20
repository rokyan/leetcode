// https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/

class Solution
{
public:
    bool canSplitArray(std::vector<int>& nums, int m)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<char>> dp(n, std::vector<char>(n));

        for (auto i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (auto len = 2; len <= n; len++)
        {
            for (auto i = 0; i + len - 1 < n; i++)
            {
                const auto first = i;
                const auto last = i + len - 1;

                auto s = 0;

                for (auto j = first; j <= last; j++)
                {
                    s += nums[j];
                }

                for (auto j = first, t = 0; j < last; j++)
                {
                    t += nums[j];
                    s -= nums[j];

                    if ((t >= m || j == first) && (s >= m || j + 1 == last))
                    {
                        dp[first][last] |= dp[first][j] & dp[j + 1][last];
                    }

                    if (dp[first][last])
                    {
                        break;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
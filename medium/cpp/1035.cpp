// https://leetcode.com/problems/uncrossed-lines/description/

class Solution
{
public:
    int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto n = std::size(nums1);
        const auto m = std::size(nums2);

        std::vector<std::vector<int>> dp(n, std::vector<int>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                }

                if (j > 0)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
                }

                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = std::max(dp[i][j], 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0));
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
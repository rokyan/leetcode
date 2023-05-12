// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        const auto n = std::size(text1);
        const auto m = std::size(text2);

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

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

                if (text1[i] == text2[j])
                {
                    dp[i][j] = std::max(dp[i][j], 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0));
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
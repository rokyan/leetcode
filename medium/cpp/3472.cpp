// https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

class Solution
{
public:
    int longestPalindromicSubsequence(const std::string& s, int lim)
    {
        const int n = std::size(s);

        std::vector<std::vector<std::vector<int>>> dp(n,
            std::vector<std::vector<int>>(n, std::vector<int>(lim + 1)));

        for (auto i = 0; i < n; i++)
        {
            for (auto k = 0; k <= lim; k++)
            {
                dp[i][i][k] = 1;
            }
        }

        for (auto len = 2; len <= n; len++)
        {
            for (auto i = 0; i + len - 1 < n; i++)
            {
                auto j = i + len - 1;

                auto d = std::abs(s[j] - s[i]);
                d = std::min(d, 26 - d);

                for (auto k = 0; k <= lim; k++)
                {
                    dp[i][j][k] = std::max(dp[i + 1][j][k], dp[i][j - 1][k]);

                    if (k >= d)
                    {
                        dp[i][j][k] = std::max(dp[i][j][k],
                            2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1][k - d] : 0));
                    }
                }
            }
        }

        auto res = 0;

        for (auto k = 0; k <= lim; k++)
        {
            res = std::max(res, dp[0][n - 1][k]);
        }

        return res;
    }
};
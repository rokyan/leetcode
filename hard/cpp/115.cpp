// https://leetcode.com/problems/distinct-subsequences/description/

class Solution
{
public:
    int numDistinct(std::string s, std::string t)
    {
        const auto n = std::size(s);
        const auto m = std::size(t);

        std::vector<std::vector<unsigned long long>> dp(n, std::vector<unsigned long long>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m && j <= i; j++)
            {
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }

                if (s[i] == t[j])
                {
                    dp[i][j] += i > 0 && j > 0 ? dp[i - 1][j - 1] : 1;
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
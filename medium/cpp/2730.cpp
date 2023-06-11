// https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/

class Solution
{
public:
    int longestSemiRepetitiveSubstring(std::string s)
    {
        const auto n = std::size(s);

        std::vector<std::vector<int>> dp(2, std::vector<int>(n));

        dp[0][0] = dp[1][0] = 1;

        auto res = 1;

        for (auto i = 1; i < n; i++)
        {
            dp[0][i] = s[i] == s[i - 1] ? 1 : dp[0][i - 1] + 1;
            dp[1][i] = s[i] == s[i - 1] ? dp[0][i - 1] + 1 : std::max(dp[0][i - 1], dp[1][i - 1]) + 1;

            res = std::max(res, std::max(dp[0][i], dp[1][i]));
        }

        return res;
    }
};
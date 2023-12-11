// https://leetcode.com/problems/valid-palindrome-iii/description/

class Solution
{
public:
    bool isValidPalindrome(std::string s, int k)
    {
        const auto n = std::size(s);

        std::vector<std::vector<int>> dp(n, std::vector<int>(n));

        for (auto i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (auto len = 2; len <= n; len++)
        {
            for (auto i = 0; i + len - 1 < n; i++)
            {
                dp[i][i + len - 1] = std::max(dp[i][i + len - 2], dp[i + 1][i + len - 1]);

                if (s[i] == s[i + len - 1])
                {
                    dp[i][i + len - 1] = std::max(dp[i][i + len - 1], 2 + dp[i + 1][i + len - 2]);
                }
            }
        }

        return dp[0][n - 1] + k >= n;
    }
};
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution
{
private:
    static constexpr int inf = 1000'000'000;

public:
    int minInsertions(const std::string& s)
    {
        const int len = std::size(s);

        std::vector<std::vector<int>> dp(len, std::vector<int>(len, inf));

        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 0;
        }

        for (auto i = 2; i <= len; i++)
        {
            for (auto j = 0; j + i - 1 < len; j++)
            {
                auto k = j + i - 1;

                if (s[j] == s[k])
                {
                    dp[j][k] = j + 1 < k ? dp[j + 1][k - 1] : 0;
                }
                else
                {
                    dp[j][k] = j + 1 < k ? std::min(dp[j][k - 1], dp[j + 1][k]) + 1 : 1;
                }
            }
        }

        return dp[0][len - 1];
    }
};
// https://leetcode.com/problems/edit-distance/description/

class Solution
{
public:
    int minDistance(const std::string& word1, const std::string& word2)
    {
        const int n = std::size(word1);
        const int m = std::size(word2);

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                const int cost = word1[i - 1] == word2[j - 1]
                    ? 0 : 1;
                dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
            }
        }

        return dp[n][m];
    }
};
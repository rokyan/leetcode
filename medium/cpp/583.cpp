// https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        const auto len1 = std::size(word1);
        const auto len2 = std::size(word2);

        std::vector<std::vector<int>> dp(len1, std::vector<int>(len2));

        for (auto i = 0; i < len1; i++)
        {
            for (auto j = 0; j < len2; j++)
            {
                if (i > 0)
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
                }

                if (j > 0)
                {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i][j]);
                }

                if (word1[i] == word2[j])
                {
                    dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
                }
            }
        }

        return len1 + len2 - 2 * dp[len1 - 1][len2 - 1];
    }
};
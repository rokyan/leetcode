// https://leetcode.com/problems/interleaving-string/description/

class Solution
{
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3)
    {
        if (std::size(s1) + std::size(s2) != std::size(s3))
        {
            return false;
        }

        const int len1 = std::size(s1);
        const int len2 = std::size(s2);

        std::vector<std::vector<std::vector<char>>> dp(len1 + 1,
            std::vector<std::vector<char>>(len2 + 1, std::vector<char>(2, false)));

        dp[0][0][0] = dp[0][0][1] = true;

        for (auto i = 0; i <= len1; i++)
        {
            for (auto j = 0; j <= len2; j++)
            {
                for (auto k = 1; k <= i && s1[i - k] == s3[i + j - k]; k++)
                {
                    if (dp[i - k][j][1])
                    {
                        dp[i][j][0] = true;
                        break;
                    }
                }

                for (auto k = 1; k <= j && s2[j - k] == s3[i + j - k]; k++)
                {
                    if (dp[i][j - k][0])
                    {
                        dp[i][j][1] = true;
                        break;
                    }
                }
            }
        }

        return dp[len1][len2][0] || dp[len1][len2][1];
    }
};
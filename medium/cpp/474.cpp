// https://leetcode.com/problems/ones-and-zeroes/description/

class Solution
{
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n)
    {
        const auto len = std::size(strs);

        std::vector<std::vector<std::vector<int>>> dp(len + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1)));

        auto res = 0;

        for (auto k = 1; k <= len; k++)
        {
            auto ones = 0;
            auto zeroes = 0;

            for (auto c : strs[k - 1])
            {
                if (c == '1')
                {
                    ones++;
                }
                else
                {
                    zeroes++;
                }
            }

            for (auto i = 0; i <= n; i++)
            {
                for (auto j = 0; j <= m; j++)
                {
                    dp[k][i][j] = dp[k - 1][i][j];
                    
                    if (i >= ones && j >= zeroes)
                    {
                        dp[k][i][j] = std::max(dp[k][i][j], 1 + dp[k - 1][i - ones][j - zeroes]);
                        res = std::max(res, dp[k][i][j]);
                    }
                }
            }
        }

        return res;
    }
};
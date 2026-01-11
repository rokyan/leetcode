// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

class Solution
{
public:
    int minimumDeleteSum(const std::string& s1, const std::string& s2)
    {
        const int n = s1.size();
        const int m = s2.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);

                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + get_ascii_code(s1[i - 1]));
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += get_ascii_code(s1[i]);
        }

        for (int j = 0; j < m; j++)
        {
            sum += get_ascii_code(s2[j]);
        }

        return sum - 2 * dp[n][m];
    }

private:
    int get_ascii_code(char c)
    {
        return c - 'a' + 97;
    }
};
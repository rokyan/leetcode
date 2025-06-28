// https://leetcode.com/problems/palindrome-partitioning-iii/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int palindromePartition(const std::string& s, int k)
    {
        const int n = std::size(s);

        std::vector<std::vector<int>> pre(n, std::vector<int>(n));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j <= i; j++)
            {
                pre[j][i] = count(s, j, i);
            }
        }

        std::vector<std::vector<int>> dp(k, std::vector<int>(n, inf));

        for (auto i = 0; i < n; i++)
        {
            dp[0][i] = pre[0][i];
        }

        for (auto i = 1; i < k; i++)
        {
            for (auto j = i; j < n; j++)
            {
                for (auto l = i; l <= j; l++)
                {
                    if (dp[i - 1][l - 1] != inf)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i - 1][l - 1] + pre[l][j]);
                    }
                }
            }
        }

        return dp[k - 1][n - 1] == inf ? 0 : dp[k - 1][n - 1];
    }

private:
    int count(const std::string& s, int l, int r)
    {
        const auto len = r - l + 1;

        if (len == 1)
        {
            return 0;
        }

        auto i = l + len / 2;
        auto j = i;

        if (len % 2 == 0)
        {
            i--;
        }

        auto cnt = 0;

        while (i >= l && j <= r)
        {
            if (s[i--] != s[j++])
            {
                cnt++;
            }
        }

        return cnt;
    }
};
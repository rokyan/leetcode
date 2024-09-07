// https://leetcode.com/problems/equalize-strings-by-adding-or-removing-characters-at-ends/description/

class Solution
{
public:
    int minOperations(const std::string& initial, const std::string& target)
    {
        const auto n = std::size(initial);
        const auto m = std::size(target);

        std::vector<std::vector<int>> dp(n, std::vector<int>(m));

        auto res = static_cast<int>(n + m);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (initial[i] == target[j])
                {
                    dp[i][j] = 1;

                    if (i > 0 && j > 0)
                    {
                        dp[i][j] += dp[i - 1][j - 1];
                    }

                    const auto ops_count = n + m - 2 * dp[i][j];

                    res = res == -1 ? ops_count : std::min<int>(res, ops_count);
                }
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/longest-ideal-subsequence/description/

class Solution
{
public:
    int longestIdealString(std::string s, int k)
    {
        const auto n = std::size(s);

        std::vector<std::vector<int>> dp(n, std::vector<int>(26));

        dp[0][s[0] - 'a'] = 1;

        for (auto i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1];

            const auto cur = s[i] - 'a';

            for (auto c = 0; c < 26; c++)
            {
                if (std::abs(c - cur) <= k)
                {
                    dp[i][cur] = std::max(dp[i][cur], dp[i - 1][c] + 1);
                }
            }
        }

        return *std::max_element(std::begin(dp.back()), std::end(dp.back()));
    }
};
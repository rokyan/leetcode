// https://leetcode.com/problems/construct-string-with-minimum-cost-easy/description/

class Solution
{
public:
    int minimumCost(
        const std::string& target,
        const std::vector<std::string>& words,
        const std::vector<int>& costs)
    {
        const int n = std::size(target);

        std::vector<int> dp(n, -1);

        std::string_view sw{target};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < std::size(words); j++)
            {
                const int len = std::size(words[j]);
                const int startPos = i - len + 1;

                if (startPos >= 0
                    && words[j] == sw.substr(startPos, len)
                    && (startPos == 0 || dp[startPos - 1] != -1))
                {
                    const auto upd = costs[j] + (startPos > 0 ? dp[startPos - 1] : 0);
                    dp[i] = dp[i] == -1 ? upd : std::min(dp[i], upd);
                }
            }
        }

        return dp.back();
    }
};
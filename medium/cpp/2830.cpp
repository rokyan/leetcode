// https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/

class Solution
{
public:
    int maximizeTheProfit(int n, std::vector<std::vector<int>>& offers)
    {
        std::vector<int> dp(n);

        std::sort(std::begin(offers), std::end(offers), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });

        for (auto i = 0, p = 0; i < n; i++)
        {
            if (i > 0)
            {
                dp[i] = dp[i - 1];
            }

            while (p < std::size(offers) && offers[p][1] == i)
            {
                const auto earned = offers[p][2] + (offers[p][0] > 0 ? dp[offers[p][0] - 1] : 0);
                dp[i] = std::max(dp[i], earned);
                p++;
            }
        }

        // for (auto i = 0; i < n; i++) std::cout << dp[i] << " ";

        return dp.back();
    }
};
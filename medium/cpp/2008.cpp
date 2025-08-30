// https://leetcode.com/problems/maximum-earnings-from-taxi/description/

class Solution
{
public:
    long long maxTaxiEarnings(int n, std::vector<std::vector<int>>& rides)
    {
        std::vector<long long> dp(n + 1);

        std::ranges::sort(rides, [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });

        const auto m = std::size(rides);
        auto res = 0LL;

        for (auto p = 1, idx = 0; p <= n; p++)
        {
            dp[p] = dp[p - 1];

            while (idx < m && rides[idx][1] < p)
            {
                idx++;
            }

            while (idx < m && rides[idx][1] == p)
            {
                dp[p] = std::max(dp[p], dp[rides[idx][0]] + rides[idx][1] - rides[idx][0] + rides[idx][2]);
                idx++;
            }

            res = std::max(res, dp[p]);
        }

        return res;
    }
};
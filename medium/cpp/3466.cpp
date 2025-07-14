// https://leetcode.com/problems/maximum-coin-collection/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000'000'000LL;

public:
    long long maxCoins(const std::vector<int>& lane1, const std::vector<int>& lane2)
    {
        const auto n = std::size(lane1);

        std::vector<std::vector<std::vector<long long>>> dp
            (n, std::vector<std::vector<long long>>(2, std::vector<long long>(3, -inf)));
        dp[0][0][0] = lane1[0];
        dp[0][1][1] = lane2[0];

        auto res = std::max<long long>(lane1[0], lane2[0]);

        for (auto i = 1; i < n; i++)
        {
            dp[i][0][0] = lane1[i];
            dp[i][1][1] = lane2[i];

            for (auto laneId = 0; laneId < 2; laneId++)
            {
                for (auto switches = 0; switches <= 2; switches++)
                {
                    dp[i][laneId][switches] = std::max(dp[i][laneId][switches],
                        (laneId == 0 ? lane1[i] : lane2[i]) + dp[i - 1][laneId][switches]);

                    if (switches > 0)
                    {
                        dp[i][laneId][switches] = std::max(dp[i][laneId][switches],
                            (laneId == 0 ? lane1[i] : lane2[i]) + dp[i - 1][laneId ^ 1][switches - 1]);
                    }

                    res = std::max(res, dp[i][laneId][switches]);
                }
            }
        }

        return res;
    }
};
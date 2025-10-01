// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

class Solution
{
public:
    int jobScheduling(
        const std::vector<int>& startTime,
        const std::vector<int>& endTime,
        const std::vector<int>& profit)
    {
        const auto n = std::size(startTime);

        std::vector<int> dp(n);
        auto res = 0;

        std::vector<std::tuple<int, int, int>> segs(n);

        for (auto i = 0; i < n; i++)
        {
            segs[i] = {startTime[i], endTime[i], profit[i]};
        }

        std::ranges::sort(segs, [](const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
            return std::get<1>(lhs) < std::get<1>(rhs);
        });

        for (auto i = 0; i < n; i++)
        {
            if (i > 0)
            {
                dp[i] = dp[i - 1];
            }

            const auto start = std::get<0>(segs[i]);

            const auto it = std::upper_bound(std::cbegin(segs), std::next(std::cbegin(segs), i),
                start, [](int value, const std::tuple<int, int, int>& e) {
                    return value < std::get<1>(e);
            });

            auto val = std::get<2>(segs[i]);

            if (it != std::cbegin(segs))
            {
                const auto prevIdx = std::distance(std::cbegin(segs), std::prev(it));
                val += dp[prevIdx];
            }

            dp[i] = std::max(dp[i], val);

            res = std::max(res, dp[i]);
        }

        return res;
    }
};
// https://leetcode.com/problems/two-best-non-overlapping-events/description/

class Solution
{
public:
    int maxTwoEvents(std::vector<std::vector<int>>& events)
    {
        const auto n = std::size(events);

        std::sort(std::begin(events), std::end(events), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });

        std::vector<int> dp(n);

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            dp[i] = events[i][2];
            res = std::max(res, events[i][2]);

            if (i > 0)
            {
                auto pos = std::upper_bound(std::begin(events), std::begin(events) + i, events[i][0] - 1, [](const auto& lhs, const auto rhs) {
                    return lhs < rhs[1];
                }) - std::begin(events);

                if (--pos >= 0)
                {
                    res = std::max(res, events[i][2] + dp[pos]);
                }

                dp[i] = std::max(dp[i], dp[i - 1]);
            }
        }

        return res;
    }
};
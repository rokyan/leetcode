// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/

class Solution
{
public:
    int maxFreeTime(int eventTime,
        const std::vector<int>& startTime, const std::vector<int>& endTime)
    {
        const int n = std::size(startTime);

        auto prev = 0;
        auto res = startTime[0];

        for (auto i = 0; i < n; i++)
        {
            const auto next = i + 1 < n ? startTime[i + 1] : eventTime;
            res = std::max(res, startTime[i] - prev + next - endTime[i]);
            prev = endTime[i];
        }

        prev = 0;
        auto free = startTime[0] - prev;
        prev = endTime[0];

        for (auto i = 1; i < n; i++)
        {
            if (free >= endTime[i] - startTime[i])
            {
                const auto next = i + 1 < n ? startTime[i + 1] : eventTime;

                res = std::max(res, next - prev);
            }

            free = std::max(free, startTime[i] - prev);
            prev = endTime[i];
        }

        prev = eventTime;
        free = prev - endTime[n - 1];
        prev = startTime[n - 1];

        for (auto i = n - 2; i >= 0; i--)
        {
            if (free >= endTime[i] - startTime[i])
            {
                const auto next = i - 1 >= 0 ? endTime[i - 1] : 0;

                res = std::max(res, prev - next);
            }

            free = std::max(free, prev - endTime[i]);
            prev = startTime[i];
        }

        return res;
    }
};
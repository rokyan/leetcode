// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/

class Solution
{
public:
    int maxFreeTime(int eventTime, int k,
        const std::vector<int>& startTime, const std::vector<int>& endTime)
    {
        const auto n = std::size(startTime);

        auto sum = 0;
        std::deque<int> dq;

        auto prev = 0;
        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            const auto diff = startTime[i] - prev;
            res = std::max(res, sum + diff);

            sum += diff;
            dq.push_back(diff);

            if (std::size(dq) > k)
            {
                sum -= dq.front();
                dq.pop_front();
            }

            prev = endTime[i];
        }

        res = std::max(res, sum + eventTime - prev);

        return res;
    }
};
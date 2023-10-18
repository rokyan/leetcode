// https://leetcode.com/problems/minimum-processing-time/description/

class Solution
{
public:
    int minProcessingTime(std::vector<int>& processorTime, std::vector<int>& tasks)
    {
        std::sort(std::begin(processorTime), std::end(processorTime), std::greater<>{});
        std::sort(std::begin(tasks), std::end(tasks));

        auto res = 0;

        for (auto i = 0; i < std::size(tasks); i++)
        {
            const auto pid = i / 4;
            res = std::max(res, processorTime[pid] + tasks[i]);
        }

        return res;
    }
};
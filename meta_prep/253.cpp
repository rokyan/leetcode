#include <ranges>

class Solution
{
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals)
    {
        std::ranges::sort(intervals);

        std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
        min_heap.push(intervals.front()[1]);

        for (const auto& interval : intervals | std::views::drop(1))
        {
            if (min_heap.top() <= interval[0])
            {
                min_heap.pop();
            }

            min_heap.push(interval[1]);
        }

        return std::size(min_heap);
    }
};
// https://leetcode.com/problems/remove-covered-intervals/

class Solution
{
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals)
    {
        std::sort(std::begin(intervals), std::end(intervals), [](const auto& left, const auto& right) {
            return left[0] < right[0] || left[0] == right[0] && left[1] > right[1];
        });
        
        auto right_max = intervals[0][1];
        auto covered = 0;
        
        for (std::size_t pos = 1; pos < std::size(intervals); pos++)
        {
            if (intervals[pos][1] <= right_max)
            {
                covered++;
            }
            
            right_max = std::max(right_max, intervals[pos][1]);
        }
        
        return std::size(intervals) - covered;
    }
};
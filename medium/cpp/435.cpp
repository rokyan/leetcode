// https://leetcode.com/problems/non-overlapping-intervals/

class Solution
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
        std::sort(std::begin(intervals), std::end(intervals), [](const auto& left, const auto& right) {
            return left[1] < right[1] || left[1] == right[1] && left[0] < right[0];
        });
        
        auto cur = intervals[0];
        
        auto answer = 0;
        
        for (std::size_t i = 1; i < std::size(intervals); i++)
        {
            const auto interval = intervals[i];
            
            if (interval[0] < cur[1])
            {
                answer++;
            }
            else
            {
                cur = interval;
            }
        }
        
        return answer;
    }
};
// https://leetcode.com/problems/merge-intervals/

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::vector<std::vector<int>> res;
        
        std::sort(std::begin(intervals), std::end(intervals), [](const auto& left, const auto& right) {
            return left[0] < right[0] || left[0] == right[0] && left[1] < right[1];
        });
        
        auto cur = intervals[0];
        
        for (std::size_t i = 1; i < std::size(intervals); i++)
        {
            const auto interval = intervals[i];
            
            if (interval[0] >= cur[0] && interval[0] <= cur[1])
            {
                cur[1] = std::max(cur[1], interval[1]);
            }
            else
            {
                res.push_back(cur);
                cur = interval;
            }
        }
        
        res.push_back(cur);
        
        return res;
    }
};
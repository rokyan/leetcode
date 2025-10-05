class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::ranges::sort(intervals);

        std::vector<std::vector<int>> res;

        for (const auto& interval : intervals)
        {
            if (res.empty() || res.back()[1] < interval[0])
            {
                res.push_back(interval);
            }
            else
            {
                res.back()[1] = std::max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
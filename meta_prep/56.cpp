class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::ranges::sort(intervals, [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        std::vector<std::vector<int>> merged;
        merged.reserve(std::size(intervals));

        for (const auto& interval : intervals)
        {
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                merged.push_back(interval);
            }
            else
            {
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
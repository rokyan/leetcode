// https://leetcode.com/problems/minimize-connected-groups-by-inserting-interval/description/

class Solution
{
public:
    int minConnectedGroups(std::vector<std::vector<int>>& intervals, int k)
    {
        std::ranges::sort(intervals);

        std::vector<std::vector<int>> merged;
        merged.reserve(std::size(intervals));

        merged.push_back(intervals.front());

        for (auto i = 1; i < std::size(intervals); i++)
        {
            if (intervals[i][0] <= merged.back()[1])
            {
                merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }

        auto val = 0;

        for (auto l = 0, r = 0; r < std::size(merged); r++)
        {
            while (merged[r][0] - merged[l][1] > k)
            {
                l++;
            }

            val = std::max(val, r - l + 1);
        }

        return std::size(merged) - val + 1;
    }
};
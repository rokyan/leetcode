// https://leetcode.com/problems/find-maximal-uncovered-ranges/description/

class Solution
{
public:
    std::vector<std::vector<int>> findMaximalUncoveredRanges(
        int n, std::vector<std::vector<int>>& ranges)
    {
        std::vector<int> last{-1, -1};

        std::ranges::sort(ranges, [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        std::vector<std::vector<int>> res;
        res.reserve(std::size(ranges));

        for (const auto& range : ranges)
        {
            if (range[0] > last[1])
            {
                if (last[1] + 1 <= range[0] - 1)
                {
                    res.push_back({last[1] + 1, range[0] - 1});
                }

                last = range;
            }
            else
            {
                last[1] = std::max(range[1], last[1]);
            }
        }

        if (last[1] + 1 <= n - 1)
        {
            res.push_back({last[1] + 1, n - 1});
        }

        return res;
    }
};
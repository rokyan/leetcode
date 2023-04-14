// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/

class Solution
{
public:
    int countWays(std::vector<std::vector<int>>& ranges)
    {
        std::sort(std::begin(ranges), std::end(ranges), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        auto p = ranges[0][1];
        auto cnt = 1;

        for (auto i = 1; i < std::size(ranges); i++)
        {
            if (ranges[i][0] > p)
            {
                cnt++;
            }

            p = std::max(p, ranges[i][1]);
        }

        auto res = 1;

        while (cnt--)
        {
            res *= 2;
            res %= 1000 * 1000 * 1000 + 7;
        }

        return res;
    }
};
// https://leetcode.com/problems/find-the-number-of-copy-arrays/description/

class Solution
{
public:
    int countArrays(const std::vector<int>& original, const std::vector<std::vector<int>>& bounds)
    {
        auto lo = bounds.front()[0];
        auto hi = bounds.front()[1];

        for (auto i = 1; i < std::size(original); i++)
        {
            const auto diff = original[i] - original[i - 1];

            auto nextLo = lo + diff;
            auto nextHi = hi + diff;

            nextLo = std::max(nextLo, bounds[i][0]);
            nextHi = std::min(nextHi, bounds[i][1]);

            if (nextLo > nextHi)
            {
                return 0;
            }

            lo = nextLo;
            hi = nextHi;
        }

        return hi - lo + 1;
    }
};
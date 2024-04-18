// https://leetcode.com/problems/moving-stones-until-consecutive-ii/description/

class Solution
{
public:
    std::vector<int> numMovesStonesII(std::vector<int>& stones)
    {
        const auto n = static_cast<int>(std::size(stones));

        std::sort(std::begin(stones), std::end(stones));

        auto hi = std::max(stones[n - 2] - stones[0], stones[n - 1] - stones[1]) - n + 2;
        auto lo = n;

        for (auto l = 0, r = 0; r < n; r++)
        {
            while (stones[r] - stones[l] >= n)
            {
                l++;
            }

            if (r - l + 1 == n - 1 && stones[r] - stones[l] == n - 2)
            {
                lo = std::min(lo, 2);
            }
            else
            {
                lo = std::min(lo, n - (r - l + 1));
            }
        }

        return { lo, hi };
    }
};
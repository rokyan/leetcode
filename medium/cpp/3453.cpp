// https://leetcode.com/problems/separate-squares-i/description/

class Solution
{
public:
    double separateSquares(const std::vector<std::vector<int>>& squares)
    {
        auto lo = .0;
        auto hi = 1e9;
        const auto eps = .000001;

        while (hi - lo > eps)
        {
            const auto mid = (lo + hi) / 2;
            auto below = .0;
            auto above = .0;

            for (const auto& sq : squares)
            {
                if (sq[1] >= mid)
                {
                    above += 1. * sq[2] * sq[2];
                }
                else if (sq[1] + sq[2] <= mid)
                {
                    below += 1. * sq[2] * sq[2];
                }
                else
                {
                    below += 1. * (mid - sq[1]) * sq[2];
                    above += 1. * (sq[1] + sq[2] - mid) * sq[2];
                }
            }

            if (below < above)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }
};
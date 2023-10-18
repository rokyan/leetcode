// https://leetcode.com/problems/minimum-time-to-repair-cars/description/

class Solution
{
public:
    long long repairCars(std::vector<int>& ranks, int cars)
    {
        auto lo = 0LL;
        auto hi = 1LL * cars * cars * (*std::max_element(std::begin(ranks), std::end(ranks)));

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto tot = 0;

            for (auto&& rank : ranks)
            {
                tot += static_cast<long long>(std::sqrt(mid / rank));

                if (tot >= cars)
                {
                    break;
                }
            }

            if (tot >= cars)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }
};	
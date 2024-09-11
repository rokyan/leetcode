// https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/description/

class Solution
{
public:
    int maxPossibleScore(std::vector<int>& start, int d)
    {
        std::sort(std::begin(start), std::end(start));

        const auto n = std::size(start);

        auto lo = 0U;
        auto hi = 2 * 1000'000'000U;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo + 1) / 2;
            auto check = true;
            auto p = static_cast<unsigned int>(start[0]);

            for (auto i = 1; i < n; i++)
            {
                auto min_next = p + mid;

                if (min_next > start[i] + d)
                {
                    check = false;
                    break;
                }

                p = std::max<unsigned int>(min_next, start[i]);
            }

            if (check)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
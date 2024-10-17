// https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/description/

#include <ranges>

class Solution
{
public:
    long long maximumTotalSum(std::vector<int>& maximumHeight)
    {
        std::sort(std::begin(maximumHeight), std::end(maximumHeight), std::greater<int>{});

        auto last = maximumHeight.front();
        auto res = static_cast<long long>(last);

        for (auto height : maximumHeight | std::views::drop(1))
        {
            last = std::min(last - 1, height);

            if (last == 0)
            {
                return -1;
            }

            res += last;
        }

        return res;
    }
};
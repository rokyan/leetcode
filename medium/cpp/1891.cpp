// https://leetcode.com/problems/cutting-ribbons/description/

class Solution
{
public:
    int maxLength(std::vector<int>& ribbons, int k)
    {
        if (std::accumulate(std::begin(ribbons), std::end(ribbons), 0LL) < k)
        {
            return 0;
        }

        auto lo = 1;
        auto hi = *std::max_element(std::begin(ribbons), std::end(ribbons)) + 1;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto tot = 0LL;

            for (auto i = 0; i < std::size(ribbons) && tot < k; i++)
            {
                tot += ribbons[i] / mid;
            }

            if (tot >= k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo - 1;
    }
};
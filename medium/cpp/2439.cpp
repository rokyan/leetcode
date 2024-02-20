// https://leetcode.com/problems/minimize-maximum-of-array/description/

class Solution
{
public:
    int minimizeArrayValue(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        auto [lo_pt, hi_pt] = std::minmax_element(std::cbegin(nums), std::cend(nums));
        auto lo = *lo_pt;
        auto hi = *hi_pt;

        while (lo < hi)
        {
            std::vector<long long> cp(n);
            std::copy(std::cbegin(nums), std::cend(nums), std::begin(cp));

            const auto mid = lo + (hi - lo) / 2;

            for (auto i = n - 1; i >= 1; i--)
            {
                if (cp[i] > mid)
                {
                    cp[i - 1] += cp[i] - mid;
                    cp[i] = mid;
                }
            }

            auto pass = true;

            for (auto i = 0; i < n && pass; i++)
            {
                pass = cp[i] <= mid;
            }

            if (pass)
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
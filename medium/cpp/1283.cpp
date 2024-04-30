// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution
{
public:
    int smallestDivisor(std::vector<int>& nums, int threshold)
    {
        auto lo = 1;
        auto hi = *std::max_element(std::cbegin(nums), std::cend(nums));

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto s = 0;

            for (auto num : nums)
            {
                s += (num + mid - 1) / mid;
            }

            if (s <= threshold)
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
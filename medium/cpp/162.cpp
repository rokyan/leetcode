// https://leetcode.com/problems/find-peak-element/description/

class Solution
{
public:
    int findPeakElement(std::vector<int>& nums)
    {
        auto lo = 0;
        auto hi = static_cast<int>(std::size(nums)) - 1;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[mid + 1])
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
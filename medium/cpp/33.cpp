// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        const auto n = static_cast<int>(std::size(nums));

        auto lo = 0;
        auto hi = n - 1;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        const auto shift = lo;

        lo = 0;
        hi = n - 1;

        while (lo <= hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            const auto shifted = (mid + shift) % n;

            if (nums[shifted] < target)
            {
                lo = mid + 1;
            }
            else if (nums[shifted] > target)
            {
                hi = mid - 1;
            }
            else
            {
                return shifted;
            }
        }

        return -1;
    }
};
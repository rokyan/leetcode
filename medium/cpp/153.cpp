// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution
{
public:
    int findMin(std::vector<int>& nums)
    {
        auto lo = 0;
        auto hi = static_cast<int>(std::size(nums)) - 1;

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

        return nums[lo];
    }
};
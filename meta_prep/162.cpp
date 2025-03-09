class Solution
{
public:
    int findPeakElement(const std::vector<int>& nums)
    {
        const int n = std::size(nums);

        auto lo = 0;
        auto hi = n - 1;

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
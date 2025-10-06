class Solution
{
public:
    int findPeakElement(std::vector<int>& nums)
    {
        const int n = std::size(nums);

        if (n == 1)
        {
            return 0;
        }

        int lo = 0;
        int hi = n - 1;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (nums[mid] < nums[mid + 1])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }
};
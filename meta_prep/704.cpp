class Solution
{
public:
    int search(const std::vector<int>& nums, int target)
    {
        int lo = 0;
        int hi = std::size(nums) - 1;

        while (lo <= hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else if (nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};
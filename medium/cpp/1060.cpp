// https://leetcode.com/problems/missing-element-in-sorted-array/

class Solution
{
public:
    int missingElement(std::vector<int>& nums, int k)
    {
        auto lo = 0;
        auto hi = std::size(nums) - 1;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            const auto mis = nums[mid] - nums[0] - mid;

            if (mis >= k)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        // std::cout << lo << std::endl;

        const auto mis = nums[lo] - nums[0] - lo;

        if (mis < k)
        {
            return nums.back() + (k - mis);
        }

        return nums[lo] - (mis - k + 1);    
    }
};
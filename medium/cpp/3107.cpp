// https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/

class Solution
{
public:
    long long minOperationsToMakeMedianK(std::vector<int>& nums, int k)
    {
        std::ranges::sort(nums);

        const int mid = std::size(nums) / 2;

        long long res = std::abs(k - nums[mid]);

        for (auto i = mid - 1; i >= 0; i--)
        {
            if (nums[i] > k)
            {
                res += nums[i] - k;
            }
        }

        for (auto i = mid + 1; i < std::size(nums); i++)
        {
            if (nums[i] < k)
            {
                res += k - nums[i];
            }
        }

        return res;
    }
};
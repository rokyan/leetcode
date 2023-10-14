// https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution
{
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k)
    {
        auto res = 0;

        for (auto l = 0, r = 0, p = 1; r < std::size(nums); r++)
        {
            p *= nums[r];

            while (l <= r && p >= k)
            {
                p /= nums[l++];
            }

            res += r - l + 1;
        }

        return res;
    }
};
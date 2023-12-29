// https://leetcode.com/problems/minimize-product-sum-of-two-arrays/description/

class Solution
{
public:
    int minProductSum(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::sort(std::begin(nums1), std::end(nums1));
        std::sort(std::begin(nums2), std::end(nums2), std::greater<>{});

        auto res = 0;

        for (auto i = 0; i < std::size(nums1); i++)
        {
            res += nums1[i] * nums2[i];
        }

        return res;
    }
};
// https://leetcode.com/problems/minimum-operations-to-transform-array/description/

class Solution
{
public:
    long long minOperations(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        long long res = 1;
        int lastAdd = std::abs(nums1.front() - nums2.back());

        const int n = std::size(nums1);

        for (int i = 0; i < n; i++)
        {
            if (nums1[i] <= nums2[i])
            {
                res += nums2[i] - nums1[i];

                if (nums2.back() < nums1[i])
                {
                    lastAdd = std::min(lastAdd, nums1[i] - nums2.back());
                }
                else if (nums2.back() > nums2[i])
                {
                    lastAdd = std::min(lastAdd, nums2.back() - nums2[i]);
                }
                else
                {
                    lastAdd = 0;
                }
            }
            else
            {
                res += nums1[i] - nums2[i];

                if (nums2.back() < nums2[i])
                {
                    lastAdd = std::min(lastAdd, nums2[i] - nums2.back());
                }
                else if (nums2.back() > nums1[i])
                {
                    lastAdd = std::min(lastAdd, nums2.back() - nums1[i]);
                }
                else
                {
                    lastAdd = 0;
                }
            }
        }

        return res + lastAdd;
    }
};
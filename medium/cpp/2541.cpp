// https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/

class Solution
{
public:
    long long minOperations(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        if (k == 0)
        {
            return (nums1 == nums2) ? 0 : -1;
        }

        long long cnt[2] { 0 };

        const auto n = std::size(nums1);

        for (auto i = 0; i < n; i++)
        {
            if (nums1[i] > nums2[i])
            {
                const auto d = nums1[i] - nums2[i];

                if (d % k)
                {
                    return -1;
                }
                else
                {
                    cnt[0] += d / k;
                }
            }
            else
            {
                const auto d = nums2[i] - nums1[i];

                if (d % k)
                {
                    return -1;
                }
                else
                {
                    cnt[1] += d / k;
                }
            }
        }

        return cnt[0] == cnt[1] ? cnt[0] : -1;
    }
};
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/

class Solution
{
public:
    long long minSum(
        const std::vector<int>& nums1,
        const std::vector<int>& nums2)
    {
        auto zeroes1 = 0;
        auto sum1 = 0LL;
        auto zeroes2 = 0;
        auto sum2 = 0LL;

        for (auto i = 0; i < std::size(nums1); i++)
        {
            sum1 += nums1[i];
            zeroes1 += nums1[i] == 0;
        }

        for (auto i = 0; i < std::size(nums2); i++)
        {
            sum2 += nums2[i];
            zeroes2 += nums2[i] == 0;
        }

        const auto minSum1 = sum1 + zeroes1;
        const auto minSum2 = sum2 + zeroes2;

        if (minSum1 < minSum2)
        {
            if (zeroes1 == 0)
            {
                return -1;
            }
            else
            {
                return minSum2;
            }
        }

        if (minSum2 < minSum1)
        {
            if (zeroes2 == 0)
            {
                return -1;
            }
            else
            {
                return minSum1;
            }
        }

        return minSum1;
    }
};
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int minSwap(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto n = std::size(nums1);

        std::vector<int> dp{ 0, 1 };
        std::vector<int> ndp{ inf, inf };

        for (auto i = 1; i < n; i++)
        {
            if (dp[0] != inf)
            {
                if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
                {
                    ndp[0] = std::min(ndp[0], dp[0]);
                }

                if (nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1])
                {
                    ndp[1] = std::min(ndp[1], dp[0] + 1);
                }
            }

            if (dp[1] != inf)
            {
                if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
                {
                    ndp[1] = std::min(ndp[1], dp[1] + 1);
                }

                if (nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1])
                {
                    ndp[0] = std::min(ndp[0], dp[1]);
                }
            }

            dp[0] = ndp[0]; ndp[0] = inf;
            dp[1] = ndp[1]; ndp[1] = inf;
        }

        return std::min(dp.front(), dp.back());
    }
};
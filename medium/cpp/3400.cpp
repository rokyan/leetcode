// https://leetcode.com/problems/maximum-number-of-matching-indices-after-right-shifts/description/

class Solution
{
public:
    int maximumMatchingIndices(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto n = std::size(nums1);
        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            auto cnt = 0;
            for (auto i = 0; i < n; i++)
            {
                cnt += nums1[i] == nums2[i];
            }

            res = std::max(res, cnt);

            std::rotate(std::begin(nums1), std::next(std::begin(nums1)), std::end(nums1));
        }

        return res;
    }
};
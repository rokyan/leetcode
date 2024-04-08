// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/

class Solution
{
public:
    int numTriplets(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_map<long long, int> cnt;

        for (auto num : nums1)
        {
            cnt[1LL * num * num]++;
        }

        auto res = 0;

        for (auto j = 0; j + 1 < std::size(nums2); j++)
        {
            for (auto k = j + 1; k < std::size(nums2); k++)
            {
                res += cnt[1LL * nums2[j] * nums2[k]];
            }
        }

        cnt.clear();

        for (auto num : nums2)
        {
            cnt[1LL * num * num]++;
        }

        for (auto j = 0; j + 1 < std::size(nums1); j++)
        {
            for (auto k = j + 1; k < std::size(nums1); k++)
            {
                res += cnt[1LL * nums1[j] * nums1[k]];
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/maximum-size-of-a-set-after-removals/description/

class Solution
{
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2)
    {
        const int n = std::size(nums1);

        std::unordered_set<int> s1(std::cbegin(nums1), std::cend(nums1));
        std::unordered_set<int> s2(std::cbegin(nums2), std::cend(nums2));

        auto take1 = 0;

        for (auto num : s1)
        {
            if (s2.find(num) == std::cend(s2))
            {
                take1++;
            }
        }

        auto take2 = 0;

        for (auto num : s2)
        {
            if (s1.find(num) == std::cend(s1))
            {
                take2++;
            }
        }

        if (std::min(take1, n / 2) + std::min(take2, n / 2) == n)
        {
            return n;
        }

        const auto rem = std::size(s1) - take1;

        return std::min<int>(std::min(take1, n / 2) + std::min(take2, n / 2) + rem, n);
    }
};
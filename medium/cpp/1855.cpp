// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/

class Solution
{
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        auto res = 0;

        for (auto i = 0, j = 0; i < std::size(nums1); i++)
        {           
            while (j + 1 < std::size(nums2) && nums2[j + 1] >= nums1[i])
            {
                j++;
            }

            if (j >= i && nums2[j] >= nums1[i])
            {
                res = std::max(res, j - i);
            }
        }

        return res;
    }
};
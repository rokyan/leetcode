// https://leetcode.com/problems/advantage-shuffle/description/

class Solution
{
public:
    std::vector<int> advantageCount(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto n = std::size(nums1);

        std::sort(std::begin(nums1), std::end(nums1));

        std::vector<std::pair<int, int>> nums2_wi(std::size(nums2));

        for (auto i = 0; i < n; i++)
        {
            nums2_wi[i] = { nums2[i], i };
        }

        std::sort(std::begin(nums2_wi), std::end(nums2_wi));

        std::vector<int> res(n, -1);

        for (auto i = 0, j = 0; i < n; i++)
        {
            while (j < std::size(nums1) && nums1[j] <= nums2_wi[i].first)
            {
                j++;
            }

            if (j == std::size(nums1))
            {
                break;
            }

            res[nums2_wi[i].second] = nums1[j];
            nums1[j] = -1;
        }

        for (auto i = 0, j = 0; i < n; i++)
        {
            if (nums1[i] != -1)
            {
                while (res[j] != -1)
                {
                    j++;
                }

                res[j] = nums1[i];
            }
        }

        return res;
    }
};
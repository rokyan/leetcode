// https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/description/

class Solution
{
public:
    int minOperations(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto res1 = check(nums1, nums2);
        std::swap(nums1.back(), nums2.back());
        const auto res2 = check(nums1, nums2, true);

        // std::cout << res1 << " " << res2 << std::endl;

        if (res1 == -1 && res2 == -1)
        {
            return -1;
        }

        if (res1 == -1)
        {
            return res2;
        }

        if (res2 == -1)
        {
            return res1;
        }

        return std::min(res1, res2);
    }

private:
    int check(const std::vector<int>& nums1, const std::vector<int>& nums2, bool swapped = false)
    {
        const auto n = std::size(nums1);

        auto cnt = 0;

        for (auto i = 0; i + 1 < n; i++)
        {
            if (nums1[i] > nums1[n - 1])
            {
                if (nums1[i] > nums2[n - 1] || nums2[i] > nums1[n - 1])
                {
                    return -1;
                }
                else
                {
                    cnt++;
                }
            }
            else if (nums2[i] > nums2[n - 1])
            {
                if (nums2[i] > nums1[n - 1] || nums1[i] > nums2[n - 1])
                {
                    return -1;
                }
                else
                {
                    cnt++;
                }
            }
        }

        return cnt + swapped;
    }
};
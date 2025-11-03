// https://leetcode.com/problems/minimum-index-sum-of-common-elements/description/

class Solution
{
public:
    int minimumSum(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        const int n = std::size(nums1);

        std::unordered_map<int, int> firstPos;

        for (int i = n - 1; i >= 0; i--)
        {
            firstPos[nums1[i]] = i;
        }

        const int m = std::size(nums2);

        int res = -1;

        for (int i = 0; i < n; i++)
        {
            if (const auto it = firstPos.find(nums2[i]); it != std::end(firstPos))
            {
                const int upd = it->second + i;
                res = res == -1 ? upd : std::min(res, upd);
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/

class Solution
{
public:
    int widestPairOfIndices(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_map<int, int> pref;
        pref[0] = -1;
        auto res = 0;

        for (auto i = 0, s = 0; i < std::size(nums1); i++)
        {
            s += nums1[i] - nums2[i];

            if (const auto it = pref.find(s); it != std::end(pref))
            {
                res = std::max(res, i - it->second);
            }
            else
            {
                pref.emplace(s, i);
            }
        }

        return res;
    }
};
// https://leetcode.com/problems/4sum-ii/description/

class Solution
{
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2,
        std::vector<int>& nums3, std::vector<int>& nums4)
    {
        std::unordered_map<int, int> cnt;

        for (auto num1 : nums1)
        {
            for (auto num2 : nums2)
            {
                cnt[num1 + num2]++;
            }
        }

        auto res = 0;

        for (auto num3 : nums3)
        {
            for (auto num4 : nums4)
            {
                const auto it = cnt.find(- num3 - num4);

                if (it != std::end(cnt))
                {
                    res += it->second;
                }
            }
        }

        return res;
    }
};
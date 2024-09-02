// https://leetcode.com/problems/count-alternating-subarrays/description/

class Solution
{
public:
    long long countAlternatingSubarrays(const std::vector<int>& nums)
    {
        auto res = 0LL;

        for (auto i = 0, acc = 0; i < std::size(nums); i++)
        {
            acc = 1 + (i > 0 && nums[i - 1] != nums[i] ? acc : 0);
            res += acc;
        }

        return res;
    }
};
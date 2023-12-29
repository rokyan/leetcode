// https://leetcode.com/problems/count-strictly-increasing-subarrays/description/

class Solution
{
public:
    long long countSubarrays(std::vector<int>& nums)
    {
        auto res = 0LL;
        auto len = 1;

        for (auto i = 1; i < std::size(nums); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                len++;
            }
            else
            {
                res += 1LL * len * (len + 1) / 2;
                len = 1;
            }
        }

        res += 1LL * len * (len + 1) / 2;

        return res;
    }
};
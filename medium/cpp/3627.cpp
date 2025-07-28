// https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/description/

class Solution
{
public:
    long long maximumMedianSum(std::vector<int>& nums)
    {
        std::ranges::sort(nums, std::greater<int>{});

        auto res = 0LL;

        for (auto times = 0, i = 1; times * 3 < std::size(nums); times++, i += 2)
        {
            res += nums[i];
        }

        return res;
    }
};
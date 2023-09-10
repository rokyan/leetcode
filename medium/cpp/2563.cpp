// https://leetcode.com/problems/count-the-number-of-fair-pairs/description/

class Solution
{
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper)
    {
        const auto n = std::size(nums);

        std::sort(std::begin(nums), std::end(nums));

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            const auto lt = std::lower_bound(std::begin(nums) + i + 1, std::end(nums), lower - nums[i]);

            if (lt == std::end(nums))
            {
                continue;
            }

            const auto rt = --std::upper_bound(std::begin(nums) + i + 1, std::end(nums), upper - nums[i]);

            const auto lo = lt - std::begin(nums);
            const auto hi = rt - std::begin(nums);

            const auto cnt = hi - lo + 1;

            res += cnt;
        }

        return res;
    }
};
// https://leetcode.com/problems/increasing-triplet-subsequence/description/

class Solution
{
public:
    bool increasingTriplet(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> min_on_pref(nums);

        for (auto i = 1; i < n; i++)
        {
            min_on_pref[i] = std::min(min_on_pref[i - 1], nums[i]);
        }

        auto max_on_suff = nums.back();

        for (auto i = n - 2; i > 0; i--)
        {
            if (min_on_pref[i - 1] < nums[i] && nums[i] < max_on_suff)
            {
                return true;
            }

            max_on_suff = std::max(max_on_suff, nums[i]);
        }

        return false;
    }
};
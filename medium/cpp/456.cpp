// https://leetcode.com/problems/132-pattern/description/

class Solution
{
public:
    bool find132pattern(std::vector<int>& nums)
    {
        std::multiset<int> suffix(std::begin(nums) + 1, std::end(nums));

        for (auto min_on_prefix = nums[0], pos = 1; pos < std::size(nums); pos++)
        {
            const auto val = nums[pos];

            suffix.erase(suffix.find(val));

            auto it = suffix.lower_bound(val);

            if (it != std::begin(suffix))
            {
                --it;

                if (min_on_prefix < *it)
                {
                    return true;
                }
            }

            min_on_prefix = std::min(min_on_prefix, val);
        }

        return false;
    }
};
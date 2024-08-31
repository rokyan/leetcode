// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/description/

class Solution
{
public:
    int countMatchingSubarrays(const std::vector<int>& nums, const std::vector<int>& pattern)
    {
        const auto n = std::size(nums);
        const auto m = std::size(pattern);

        auto res = 0;

        for (auto i = 0; i + m < n; i++)
        {
            auto check = true;

            for (auto k = i; k < i + m && check; k++)
            {
                if (pattern[k - i] == 1)
                {
                    check &= nums[k + 1] > nums[k];
                }

                if (pattern[k - i] == 0)
                {
                    check &= nums[k + 1] == nums[k];
                }

                if (pattern[k - i] == -1)
                {
                    check &= nums[k + 1] < nums[k];
                }
            }

            res += check;
        }

        return res;
    }
};
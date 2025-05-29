// https://leetcode.com/problems/maximum-frequency-after-subarray-operation/description/

#include <ranges>

class Solution
{
public:
    int maxFrequency(const std::vector<int>& nums, int k)
    {
        const auto tot = std::count(std::cbegin(nums), std::cend(nums), k);
        auto res = 0;

        for (auto val : std::views::iota(1, 51))
        {
            auto minSoFar = 0;
            auto maxDiff = 0;
            auto diff = 0;

            for (auto num : nums)
            {
                if (num == val)
                {
                    diff++;
                }

                if (num == k)
                {
                    diff--;
                }

                maxDiff = std::max(maxDiff, diff - minSoFar);
                minSoFar = std::min(minSoFar, diff);
            }

            res = std::max<int>(res, tot + maxDiff);
        }

        return res;
    }
};
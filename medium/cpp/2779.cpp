// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

class Solution
{
public:
    int maximumBeauty(std::vector<int>& nums, int k)
    {
        std::sort(std::begin(nums), std::end(nums));

        auto lo = *std::min_element(std::begin(nums), std::end(nums));
        auto hi = *std::max_element(std::begin(nums), std::end(nums));
        auto res = 0;

        for (auto i = lo; i <= hi; i++)
        {
            const auto first = std::lower_bound(std::begin(nums), std::end(nums), i - k);
            const auto last = std::upper_bound(std::begin(nums), std::end(nums), i + k);

            res = std::max<int>(res, std::distance(first, last));
        }

        return res;
    }
};
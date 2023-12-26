// https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/description/

class Solution
{
public:
    int minimumSwaps(std::vector<int>& nums)
    {
        const auto [min_it, max_it] = std::minmax_element(std::cbegin(nums), std::cend(nums));

        const auto min_pos = std::distance(std::cbegin(nums), min_it);
        const auto max_pos = std::distance(std::cbegin(nums), max_it);

        return min_pos + (std::size(nums) - max_pos - 1) - (min_pos > max_pos);
    }
};
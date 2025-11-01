// https://leetcode.com/problems/maximum-total-subarray-value-i/description/

class Solution
{
public:
    long long maxTotalValue(const std::vector<int>& nums, int k)
    {
        const auto [minIt, maxIt] = std::ranges::minmax_element(nums);

        return 1LL * k * (*maxIt - *minIt);
    }
};
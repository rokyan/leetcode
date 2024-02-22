// https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/

class Solution
{
public:
    int minSizeSubarray(std::vector<int>& nums, int target)
    {
        const auto n = static_cast<int>(std::size(nums));

        const auto total = std::accumulate(std::cbegin(nums), std::cend(nums), 0LL);

        auto res = -1;

        const auto add = static_cast<int>(target / total * n);
        target %= total;
        auto sum = 0LL;

        for (auto l = 0, r = 0; r < 2 * n; r++)
        {
            sum += nums[r % n];

            while (sum > target)
            {
                sum -= nums[l++ % n];
            }

            if (sum == target)
            {
                res = res == -1 ? r - l + 1 + add : std::min(res, r - l + 1 + add);
            }
        }

        return res;
    }
};
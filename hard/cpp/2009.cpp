// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

class Solution
{
public:
    int minOperations(std::vector<int>& nums)
    {
        std::ranges::sort(nums);
    
        const int n = std::size(nums);

        const int m = std::distance(
            std::begin(nums),
            std::unique(std::begin(nums), std::end(nums)));

        auto res = n;

        const auto end = std::next(std::cbegin(nums), m);

        for (auto i = 0; i < m; i++)
        {
            auto toChangeCount = n - m + i;

            const auto it = std::upper_bound(
                std::cbegin(nums),
                end,
                nums[i] + n - 1
            );

            toChangeCount += std::distance(it, end);

            res = std::min(res, toChangeCount);
        }
    
        return res;
    }
};
// https://leetcode.com/problems/minimum-removals-to-balance-array/description/

class Solution
{
public:
    int minRemoval(std::vector<int>& nums, int k)
    {
        std::ranges::sort(nums);

        auto maxLen = 1;

        for (auto i = 0; i < std::size(nums); i++)
        {
            auto minVal = 1LL * nums[i] * k;

            const auto pos = std::distance(std::cbegin(nums),
                std::upper_bound(std::cbegin(nums), std::cend(nums), minVal));

            const auto len = pos - i;
            maxLen = std::max<int>(maxLen, len);
        }

        return std::size(nums) - maxLen;
    }
};
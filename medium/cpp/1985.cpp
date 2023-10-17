// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/

class Solution
{
public:
    std::string kthLargestNumber(std::vector<std::string>& nums, int k)
    {
        const auto comp = [](const auto& lhs, const auto& rhs)
        {
            return std::size(lhs) > std::size(rhs) || std::size(lhs) == std::size(rhs) && lhs > rhs;
        };

        std::nth_element(std::begin(nums), std::begin(nums) + k - 1, std::end(nums), comp);
        return *(std::begin(nums) + k - 1);
    }
};
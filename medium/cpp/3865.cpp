// https://leetcode.com/problems/reverse-k-subarrays/description/

class Solution
{
public:
    std::vector<int> reverseSubarrays(std::vector<int>& nums, int k)
    {
        const int stride = nums.size() / k;

        for (auto it = nums.begin(); it != nums.end(); )
        {
            auto next = std::next(it, stride);
            std::reverse(it, next);
            it = next;
        }

        return nums;
    }
};
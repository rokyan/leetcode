// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution
{
public:
    int singleNonDuplicate(std::vector<int>& nums)
    {
        return std::accumulate(std::begin(nums), std::end(nums), 0, [](int x, int y) {
            return x ^ y;
        });
    }
};
// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        
        std::sort(std::begin(nums), std::end(nums));

        auto len = 1;
        auto ans = 0;

        for (std::size_t pos = 1; pos < std::size(nums); pos++)
        {
            if (nums[pos] == nums[pos - 1])
            {
                //
            }
            else if (nums[pos] == nums[pos - 1] + 1)
            {
                len++;
            }
            else
            {
                ans = std::max(ans, len);
                len = 1;
            }
        }

        return std::max(ans, len);
    }
};
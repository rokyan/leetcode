// https://leetcode.com/problems/maximize-greatness-of-an-array/description/

class Solution
{
public:
    int maximizeGreatness(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        auto left = 0;

        for (auto right = 0; right < std::size(nums); )
        {
            while (right < std::size(nums) && nums[right] <= nums[left])
            {
                right++;
            }

            if (right == std::size(nums))
            {
                break;
            }

            left++;
            right++;
        }

        return left;
    }
};
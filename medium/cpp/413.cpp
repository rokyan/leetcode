// https://leetcode.com/problems/arithmetic-slices/description/

class Solution
{
public:
    int numberOfArithmeticSlices(std::vector<int>& nums)
    {
        if (std::size(nums) < 3)
        {
            return 0;
        }
        
        auto d = nums[1] - nums[0];
        auto count = 2;
        auto answer = 0;
        
        for (auto pos = 2; pos < std::size(nums); pos++)
        {
            if (nums[pos] - nums[pos - 1] == d)
            {
                ++count;
            }
            else
            {
                d = nums[pos] - nums[pos - 1];
                count = 2;
            }

            answer += count - 2;
        }
        
        return answer;
    }
};